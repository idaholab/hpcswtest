MPIPROCS=1
OMPTHREADS=1
THREADS=1
HELP=0
XTRA_MEM=0
SIZEPERMPI=96
SUBMIT_JOB=1

HOSTNAME=`hostname`
if [ "$HOSTNAME" = "flogin1" -o "$HOSTNAME" = "flogin2" -o "$HOSTNAME" = "fbuild" -o "$HOSTNAME" = "fpbs" -o "$HOSTNAME" = "fbuild2" ]
then
CLUSTER="fission"
CORES_PER_NODE=32
CPU_TYPE="magnycours"
elif [ "$HOSTNAME" = "falcon1" -o "$HOSTNAME" = "falcon2" -o "$HOSTNAME" = "service2" -o "$HOSTNAME" = "falconviz" ]
then
CLUSTER="falcon"
CORES_PER_NODE=24
CPU_TYPE="haswell"
elif [ "$HOSTNAME" = "quark" ]
then
CLUSTER="quark"
CORES_PER_NODE=12
elif [ "$HOSTNAME" = "bechler" ]
then
CLUSTER="bechler"
CORES_PER_NODE=32
CPU_TYPE="sandybridge"
else
echo "Error: Machine $HOSTNAME is not supported."
exit 1
fi

#IOZONE_EXEC=iozone_$CLUSTER
IOZONE_EXEC=iozone
MD_EXEC=mdtest_$CLUSTER

MPI_PER_NODE=$CORES_PER_NODE


function calc_chunk {
  if [ $CPU_TYPE == "broadwell" ]
  then
     CORES_PER_NODE=36
     if [ -z $MPI_PER_NODE_SET ]
     then
        MPI_PER_NODE=$CORES_PER_NODE 
     fi
  fi
  if [ $XTRA_MEM -eq 1 ]
  then
     MPIPROCS=$(($MPIPROCS - 1))
  fi
#  TOTAL_PROCS=$(($MPIPROCS * $OMPTHREADS))
  TOTAL_PROCS=$MPIPROCS
#  echo "TOTAL_PROCS = $TOTAL_PROCS"
  NNODES=`expr $TOTAL_PROCS / $MPI_PER_NODE`
  DIV_BY_CORES_PER_NODE=`expr $TOTAL_PROCS % $CORES_PER_NODE`
  MOD_BY_MPI_PER_NODE=`expr $TOTAL_PROCS % $MPI_PER_NODE`
  STR1=""
  STR2=""
#  if [ $DIV_BY_CORES_PER_NODE -ne 0 ]
#  then
#    STR1="Warning: You have requested $TOTAL_PROCS mpi processes, it would be more efficient to"
#    STR2="         request mpi processes in multiples of $CORES_PER_NODE."
##    echo "Warning: You have requested $1 mpi processes, it would be more efficient (on Fission) to"
##    echo "         request mpi processes in multiples of 32."
#  fi
  if [ $TOTAL_PROCS -le $CORES_PER_NODE -a $MPI_PER_NODE -eq $CORES_PER_NODE ]
  then
     NNODES=1
     RPROCS1=$MPIPROCS
  elif [ $MOD_BY_MPI_PER_NODE -eq 0 ]
  then
     RPROCS1=`expr $MPIPROCS / $NNODES`
  else
     RPROCS1=$MPI_PER_NODE 
     TMP2=$(($RPROCS1 * $NNODES))
     RPROCS2=`expr $MPIPROCS - $TMP2`
  fi
#  echo "NNODES = $NNODES RPROCS1 = $RPROCS1  RPROCS2 = $RPROCS2"
#  echo "MOD_BY_MPI_PER_NODE = $MOD_BY_MPI_PER_NODE"
}


function check_command_args {
   if [ $HELP -ne 1 ]
   then
      if [ -z "$PBS_JOB_ARRAY_RANGE" -a -z "$PBS_JOB_ARRAY_FILENAME" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
	 then
            if [ -z "$WALLTIME" ]
	    then
	       echo "Error: Make sure you specify the Scheduler Walltime."
	       usage
	       exit 1
            fi
	 else
            if [ -z "$INPUT" -o -z "$WALLTIME" ]
	    then
	       if [ "$EXE_NAME" == "starccm+" ]
	       then
	          echo "Error: Make sure you specify the Sim file and PBS Walltime."
	       else
	          echo "Error: Make sure you specify the input file and PBS Walltime."
	       fi
	       usage
	       exit 1
            fi
	 fi
      else
         if [ -z "$PBS_JOB_ARRAY_RANGE" -o -z "$PBS_JOB_ARRAY_FILENAME" ]
	 then
	    echo "Error: If you want to use job arrays you need to provide the job_array_range and a job_array_filename"
	    usage
	    exit 1
	 fi
      fi
      if [ $THREADS -gt $CORES_PER_NODE ]
      then
         echo " Error: Maximum number of threads per node is $CORES_PER_NODE"
	 exit 1
      fi
   fi
   if [ -n "$PBS_JOB_ARRAY_RANGE" -a -z "$WALLTIME" ]
   then
      echo "Error: Walltime not specified on the command line."
      usage
      exit 1
   fi
   if [ $OMPTHREADS -gt $CORES_PER_NODE ]
   then
      echo " Error: You specified $OMPTHREADS threads, you cannot specify more than $CORES_PER_NODE."
      exit 1
   fi
}


function slurm_check_command_args {
   if [ $HELP -ne 1 ]
   then
      if [ -z "$JOB_ARRAY_RANGE" -a -z "$JOB_ARRAY_FILENAME" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
	 then
            if [ -z "$WALLTIME" ]
	    then
	       echo "Error: Make sure you specify the Scheduler Walltime."
	       usage
	       exit 1
            fi
	 else
            if [ -z "$INPUT" -o -z "$WALLTIME" ]
	    then
	       if [ "$EXE_NAME" == "starccm+" ]
	       then
	          echo "Error: Make sure you specify the Sim file and PBS Walltime."
	       else
	          echo "Error: Make sure you specify the input file and PBS Walltime."
	       fi
	       usage
	       exit 1
            fi
	 fi
      else
         if [ -z "$JOB_ARRAY_RANGE" -o -z "$JOB_ARRAY_FILENAME" ]
	 then
	    echo "Error: If you want to use job arrays you need to provide the job_array_range and a job_array_filename"
	    usage
	    exit 1
	 fi
      fi
      if [ $THREADS -gt $CORES_PER_NODE ]
      then
         echo " Error: Maximum number of threads per node is $CORES_PER_NODE"
	 exit 1
      fi
   fi
   if [ -n "$JOB_ARRAY_RANGE" -a -z "$WALLTIME" ]
   then
      echo "Error: Walltime not specified on the command line."
      usage
      exit 1
   fi
   if [ $OMPTHREADS -gt $CORES_PER_NODE ]
   then
      echo " Error: You specified $OMPTHREADS threads, you cannot specify more than $CORES_PER_NODE."
      exit 1
   fi
}


function set_default_jobname {
   if [ -n "$PBS_JOB_ARRAY_RANGE" ]
   then
      INPUT=job_array
   fi
   if [ -z "$JOBNAME" ]
   then
      if [ "$EXE_NAME" == "vasp" ]
      then
         JOBNAME=$NAME
      else
         JOBNAME=$INPUT
      fi
   fi
}


function slurm_set_default_jobname {
   if [ -n "$JOB_ARRAY_RANGE" ]
   then
      INPUT=job_array
   fi
   if [ -z "$JOBNAME" ]
   then
      if [ "$EXE_NAME" == "vasp" ]
      then
         JOBNAME=$NAME
      else
         JOBNAME=$INPUT
      fi
   fi
}


function pbs_set_defaults {
   echo "#PBS -N $JOBNAME" >> $1
   if [ -n "$QUEUE" ]
   then
      echo "#PBS -q $QUEUE" >> $1
   fi  
   echo "#PBS -l walltime=$WALLTIME" >> $1
   echo "#PBS -ko" >> $1
   echo "#PBS -j oe" >> $1
   if [ -n "$PROJECT" ]
   then
      echo "#PBS -P $PROJECT" >> $1
   fi  
}


function slurm_set_defaults {
   if [ -n "$JOB_ARRAY_RANGE" ]
   then
      echo "#SBATCH --job-name=${JOBNAME}"_"%a" >> $1
      echo "#SBATCH --output=$JOBNAME.o%A_%a" >> $1
      echo "#SBATCH --error=$JOBNAME.o%A_%a" >> $1
   else
      echo "#SBATCH --job-name=$JOBNAME" >> $1
      echo "#SBATCH --output=$JOBNAME.o%A" >> $1
      echo "#SBATCH --error=$JOBNAME.o%A" >> $1
   fi
   if [ -n "$QUEUE" ]
   then
      echo "#SBATCH --partition=$QUEUE" >> $1
   fi  
   echo "#SBATCH --time=$WALLTIME" >> $1
#   if [ -n "$PROJECT" ]
#   then
#      echo "#PBS -P $PROJECT" >> $1
#   fi  
}


function pbs_depends_on {
   if [ -n "$DEPENDS_ON_JOBID" ]
   then
      echo "#PBS -W depend=afterany:$DEPENDS_ON_JOBID" >> $1
   fi
}


function slurm_depends_on {
   if [ -n "$DEPENDS_ON_JOBID" ]
   then
      echo "#SBATCH --dependency=afterany:$DEPENDS_ON_JOBID" >> $1
   fi
}


function pbs_depends_on {
   if [ -n "$DEPENDS_ON_JOBID" ]
   then
      echo "#PBS -W depend=afterany:$DEPENDS_ON_JOBID" >> $1
   fi  
}


function pbs_jobarray {
   if [ -n "$PBS_JOB_ARRAY_RANGE" ]
   then
      echo "#PBS -r y" >> $1
      echo "#PBS -J $PBS_JOB_ARRAY_RANGE" >> $1
   fi  
}


function slurm_jobarray {
   if [ -n "$JOB_ARRAY_RANGE" ]
   then
      echo "#SBATCH --array $JOB_ARRAY_RANGE" >> $1
   fi  
}


function pbs_select {
   if [ $XTRA_MEM -eq 1 ]
   then
      if [  -n "$RPROCS2" ]
      then
         if [  -n "$PBS_MEM" ]
         then
            echo "#PBS -l select=1:ncpus=$CORES_PER_NODE:cputype=$CPU_TYPE:mem=$PBS_MEM:mpiprocs=1+$NNODES:ncpus=$NCPUS:cputype=$CPU_TYPE:mem=$PBS_MEM:mpiprocs=$RPROCS1+1:ncpus=$NCPUS:mpiprocs=$RPROCS2:cputype=$CPU_TYPE:mem=$PBS_MEM" >> $1
         else
            echo "#PBS -l select=1:ncpus=$CORES_PER_NODE:cputype=$CPU_TYPE:mpiprocs=1+$NNODES:ncpus=$NCPUS:mpiprocs=$RPROCS1:cputype=$CPU_TYPE+1:ncpus=$NCPUS:mpiprocs=$RPROCS2:cputype=$CPU_TYPE" >> $1
         fi  
      else
         if [  -n "$PBS_MEM" ]
         then
            echo "#PBS -l select=1:ncpus=$CORES_PER_NODE:cputype=$CPU_TYPE:mem=$PBS_MEM:mpiprocs=1+$NNODES:ncpus=$NCPUS:mpiprocs=$RPROCS1:cputype=$CPU_TYPE:mem=$PBS_MEM" >> $1
         else
            echo "#PBS -l select=1:ncpus=$CORES_PER_NODE:cputype=$CPU_TYPE:mpiprocs=1+$NNODES:ncpus=$NCPUS:mpiprocs=$RPROCS1:cputype=$CPU_TYPE" >> $1
         fi  
      fi
   else
      if [  -n "$RPROCS2" ]
      then
         if [  -n "$PBS_MEM" ]
         then
            echo "#PBS -l select=1:ncpus=$NCPUS:mem=$PBS_MEM:mpiprocs=$RPROCS2:cputype=$CPU_TYPE+$NNODES:ncpus=$NCPUS:mpiprocs=$RPROCS1:cputype=$CPU_TYPE:mem=$PBS_MEM" >> $1
         else
            echo "#PBS -l select=1:ncpus=$NCPUS:mpiprocs=$RPROCS2:cputype=$CPU_TYPE+$NNODES:ncpus=$NCPUS:mpiprocs=$RPROCS1:cputype=$CPU_TYPE" >> $1
         fi  
      else
         if [  -n "$PBS_MEM" ]
         then
            echo "#PBS -l select=$NNODES:ncpus=$NCPUS:mpiprocs=$RPROCS1:cputype=$CPU_TYPE:mem=$PBS_MEM" >> $1
         else
            echo "#PBS -l select=$NNODES:ncpus=$NCPUS:mpiprocs=$RPROCS1:cputype=$CPU_TYPE" >> $1
         fi  
      fi
   fi
}


function slurm_tasks {
   if [  -n "$MEM_PER_PROCESS" ]
   then
      echo "#SBATCH --ntasks=$MPIPROCS" >> $1
      echo "#SBATCH --ntasks-per-node=$MPI_PER_NODE" >> $1
      echo "#SBATCH --mem-per-cpu=$MEM_PER_PROCESS" >> $1
   else
      echo "#SBATCH --ntasks=$MPIPROCS" >> $1
      echo "#SBATCH --ntasks-per-node=$MPI_PER_NODE" >> $1
   fi  
}


function load_modules {
   echo "source /etc/profile.d/modules.sh" >> $1
   if [ -n "$EXTRA_MODULE_NAME1" ]
   then
      echo "module load $EXTRA_MODULE_NAME1" >> $1
   fi
   if [ -n "$EXTRA_MODULE_NAME2" ]
   then
      echo "module load $EXTRA_MODULE_NAME2" >> $1
   fi
   if [ -n "$DEBUG_JOB" ]
   then
      echo "module load use.projects utils" >> $1
   fi
   echo "module load $MODULE_NAME" >> $1
   if [ "$EXE_NAME" == "abaqus" ]
   then
      if [ -n "$GCC_MODULE_NAME" ]
      then
         echo  "module load $GCC_MODULE_NAME" >> $1
      fi
      echo  "module load $COMPILER_MODULE_NAME" >> $1
   fi
}


#function create_slurm_nodefile {
#   python /home/garvct/my_sw_development/pbs_job_submit/slurm_nodefile.py $1
#}


function slurm_create_nodefile {
   echo "export SLURM_NODEFILE=/tmp/slurm_\$SLURM_JOBID" >> $1
   echo "scontrol show hostname \$SLURM_JOB_NODELIST >& \$SLURM_NODEFILE" >> $1
}


function debug_job {
   if [ -n "$DEBUG_JOB" ]
   then
      echo "cat \$PBS_NODEFILE | uniq > mpd.hosts_\$\$" >> $1
      echo "checkBasicStatus.py -f mpd.hosts_\$\$" >> $1
#      echo "check_node_mem_pbs.sh 180 &" >> $1
   fi
# Not the best place to put this logic, but didnot want to break existing sub_app scripts.
   echo "JOB_NUM=\${PBS_JOBID%\.*}" >> $1
   if [ -z "$PBS_JOB_ARRAY_RANGE" ]
   then
      echo "if [ \$PBS_O_WORKDIR != \$HOME ]" >> $1
      echo "then" >> $1
      echo "ln -s \$HOME/\$PBS_JOBNAME.o\$JOB_NUM \$PBS_JOBNAME.o\$JOB_NUM" >> $1
      echo "fi" >> $1
   fi
}


function slurm_debug_job {
   if [ -n "$DEBUG_JOB" ]
   then
      echo "cat \$SLURM_NODEFILE | uniq > mpd.hosts_\$\$" >> $1
      echo "checkBasicStatus.py -f mpd.hosts_\$\$" >> $1
#      echo "check_node_mem_pbs.sh 180 &" >> $1
   fi
   echo "JOB_NUM=\${SLURM_JOB_ID%\.*}" >> $1
}


function setup_run_in_scratch {
   if [ -n "$SCRATCH_TYPE" ]
   then
      echo "export TMPDIR=$SCRATCH_BASE_DIR/\$\$" >> $1
      if [ $SCRATCH_TYPE != "scratch" ]
      then
         echo "for host in \`uniq \$PBS_NODEFILE\`" >> $1
         echo "do" >> $1
         echo "ssh \$host mkdir $SCRATCH_BASE_DIR/\$\$" >> $1
         echo "done" >> $1
         echo "hostfile=(\$(cat \$PBS_NODEFILE))" >> $1
         echo "echo \"Job run on \${hostfile[0]} at $SCRATCH_BASE_DIR/\$\$\"" >> $1
      else
         echo "mkdir $SCRATCH_BASE_DIR/\$\$" >> $1
         if [ -z "$PBS_JOB_ARRAY_RANGE" ]
         then
            echo "ln -s $SCRATCH_BASE_DIR/\$\$" >> $1
         fi
      fi
      if [ -z "$PBS_JOB_ARRAY_RANGE" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
         then
            echo "rsync --exclude INCAR --exclude POTCAR --exclude POSCAR --exclude KPOINTS --exclude $JOBNAME.pbs . $SCRATCH_BASE_DIR/\$\$" >> $1
         else
            echo "rsync --exclude $2 --exclude $JOBNAME.pbs . $SCRATCH_BASE_DIR/\$\$" >> $1
         fi
         echo "cd $SCRATCH_BASE_DIR/\$\$" >> $1
         if [ "$EXE_NAME" == "vasp" ]
         then
            echo "ln -s \$PBS_O_WORKDIR/INCAR && ln -s \$PBS_O_WORKDIR/KPOINTS && ln -s \$PBS_O_WORKDIR/POSCAR && ln -s \$PBS_O_WORKDIR/POTCAR" >> $1
         else
            echo "ln -s \$PBS_O_WORKDIR/$2" >> $1
         fi
      fi
   else
      echo "export TMPDIR=/tmp" >> $1
   fi
}


function slurm_setup_run_in_scratch {
   if [ -n "$SCRATCH_TYPE" ]
   then
      echo "export TMPDIR=$SCRATCH_BASE_DIR/\$\$" >> $1
      if [ $SCRATCH_TYPE != "scratch" ]
      then
         echo "for host in \`uniq \$SLURM_NODEFILE\`" >> $1
         echo "do" >> $1
         echo "ssh \$host mkdir $SCRATCH_BASE_DIR/\$\$" >> $1
         echo "done" >> $1
         echo "hostfile=(\$(cat \$SLURM_NODEFILE))" >> $1
         echo "echo \"Job run on \${hostfile[0]} at $SCRATCH_BASE_DIR/\$\$\"" >> $1
      else
         echo "mkdir $SCRATCH_BASE_DIR/\$\$" >> $1
         if [ -z "$JOB_ARRAY_RANGE" ]
         then
            echo "ln -s $SCRATCH_BASE_DIR/\$\$" >> $1
         fi
      fi
      if [ -z "$JOB_ARRAY_RANGE" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
         then
            echo "rsync --exclude INCAR --exclude POTCAR --exclude POSCAR --exclude KPOINTS --exclude $JOBNAME.sbatch . $SCRATCH_BASE_DIR/\$\$" >> $1
         else
            echo "rsync --exclude $2 --exclude $JOBNAME.sbatch . $SCRATCH_BASE_DIR/\$\$" >> $1
         fi
         echo "cd $SCRATCH_BASE_DIR/\$\$" >> $1
         if [ "$EXE_NAME" == "vasp" ]
         then
            echo "ln -s \$SLURM_SUBMIT_DIR/INCAR && ln -s \$SLURM_SUBMIT_DIR/KPOINTS && ln -s \$SLURM_SUBMIT_DIR/POSCAR && ln -s \$SLURM_SUBMIT_DIR/POTCAR" >> $1
         else
            echo "ln -s \$SLURM_SUBMIT_DIR/$2" >> $1
         fi
      fi
   else
      echo "export TMPDIR=/tmp" >> $1
   fi
}


function setup_jobarray {
   if [ -n "$PBS_JOB_ARRAY_RANGE" ]
   then
      echo "OLDIFS=\$IFS" >> $1
      echo "IFS=\$'\n'" >> $1
      echo "job_array_file=(\$(cat $PBS_JOB_ARRAY_FILENAME))" >> $1
      echo "IFS=\$OLDIFS" >> $1
      echo "job_array_file_line=( \${job_array_file[\$PBS_ARRAY_INDEX]} )" >> $1
      if [ "$EXE_NAME" == "vasp" ]
      then
         echo "dir_path=\$job_array_file_line" >> $1
      else
         echo "dir_path=\$(dirname \$job_array_file_line)" >> $1
         echo "input_name=\$(basename \$job_array_file_line)" >> $1
      fi
      if [ "$EXE_NAME" == "abaqus" ]
      then
         echo "if [[ \$input_name =~ .*\.inp ]]" >> $1
	 echo "then" >> $1
	 echo "   input_name=\$input_name" >> $1
	 echo "else" >> $1
	 echo "   input_name=\$input_name\".inp\"" >> $1
	 echo "fi" >> $1
      fi
      if [ "$EXE_NAME" == "starccm+" ]
      then
         echo "if [[ \$input_name =~ .*\.sim ]]" >> $1
	 echo "then" >> $1
	 echo "   input_name=\$input_name" >> $1
	 echo "else" >> $1
	 echo "   input_name=\$input_name\".sim\"" >> $1
	 echo "fi" >> $1
      fi
      echo "cd \$dir_path" >> $1
      if [ "$NAME" == "mc21" ]
      then
         echo "ln -sf $ND_LIBRARY_FULLPATH ND_LIBRARY" >> $1
      fi
      if [ -n "$SCRATCH_TYPE" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
	 then
            echo "rsync --exclude INCAR --exclude POTCAR --exclude POSCAR --exclude KPOINTS --exclude $JOBNAME.pbs . $SCRATCH_BASE_DIR/\$\$" >> $1
	 else
            echo "rsync --exclude \$input_name --exclude $JOBNAME.pbs . $SCRATCH_BASE_DIR/\$\$" >> $1
	 fi
         if [ $SCRATCH_TYPE == "scratch" ]
         then
            echo "ln -s $SCRATCH_BASE_DIR/\$\$" >> $1
         fi
         echo "cd $SCRATCH_BASE_DIR/\$\$" >> $1
	 if [ "$EXE_NAME" == "vasp" ]
	 then
            echo "ln -s \$dir_path/INCAR" >> $1
            echo "ln -s \$dir_path/KPOINTS" >> $1
            echo "ln -s \$dir_path/POSCAR" >> $1
            echo "ln -s \$dir_path/POTCAR" >> $1
	 else
            echo "ln -s \$dir_path/\$input_name" >> $1
	 fi
      fi
      echo "JA_JOB_NUM=\${JOB_NUM%[*}" >> $1
      echo "ln -s $HOME/\$PBS_JOBNAME.o\$JA_JOB_NUM.\$PBS_ARRAY_INDEX \$dir_path/\$PBS_JOBNAME.o\$JA_JOB_NUM.\$PBS_ARRAY_INDEX" >> $1
   fi
}


function slurm_setup_jobarray {
   if [ -n "$JOB_ARRAY_RANGE" ]
   then
      echo "OLDIFS=\$IFS" >> $1
      echo "IFS=\$'\n'" >> $1
      echo "job_array_file=(\$(cat $JOB_ARRAY_FILENAME))" >> $1
      echo "IFS=\$OLDIFS" >> $1
      echo "job_array_file_line=( \${job_array_file[\$SLURM_ARRAY_TASK_ID]} )" >> $1
      if [ "$EXE_NAME" == "vasp" ]
      then
         echo "dir_path=\$job_array_file_line" >> $1
      else
         echo "dir_path=\$(dirname \$job_array_file_line)" >> $1
         echo "input_name=\$(basename \$job_array_file_line)" >> $1
      fi
      if [ "$EXE_NAME" == "abaqus" ]
      then
         echo "if [[ \$input_name =~ .*\.inp ]]" >> $1
	 echo "then" >> $1
	 echo "   input_name=\$input_name" >> $1
	 echo "else" >> $1
	 echo "   input_name=\$input_name\".inp\"" >> $1
	 echo "fi" >> $1
      fi
      if [ "$EXE_NAME" == "starccm+" ]
      then
         echo "if [[ \$input_name =~ .*\.sim ]]" >> $1
	 echo "then" >> $1
	 echo "   input_name=\$input_name" >> $1
	 echo "else" >> $1
	 echo "   input_name=\$input_name\".sim\"" >> $1
	 echo "fi" >> $1
      fi
      echo "cd \$dir_path" >> $1
      if [ "$NAME" == "mc21" ]
      then
         echo "ln -sf $ND_LIBRARY_FULLPATH ND_LIBRARY" >> $1
      fi
      if [ -n "$SCRATCH_TYPE" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
	 then
            echo "rsync --exclude INCAR --exclude POTCAR --exclude POSCAR --exclude KPOINTS --exclude $JOBNAME.sbatch . $SCRATCH_BASE_DIR/\$\$" >> $1
	 else
            echo "rsync --exclude \$input_name --exclude $JOBNAME.sbatch . $SCRATCH_BASE_DIR/\$\$" >> $1
	 fi
         if [ $SCRATCH_TYPE == "scratch" ]
         then
            echo "ln -s $SCRATCH_BASE_DIR/\$\$" >> $1
         fi
         echo "cd $SCRATCH_BASE_DIR/\$\$" >> $1
	 if [ "$EXE_NAME" == "vasp" ]
	 then
            echo "ln -s \$dir_path/INCAR" >> $1
            echo "ln -s \$dir_path/KPOINTS" >> $1
            echo "ln -s \$dir_path/POSCAR" >> $1
            echo "ln -s \$dir_path/POTCAR" >> $1
	 else
            echo "ln -s \$dir_path/\$input_name" >> $1
	 fi
      fi
#      echo "JA_JOB_NUM=\${JOB_NUM%[*}" >> $1
#      echo "ln -s $HOME/\$PBS_JOBNAME.o\$JA_JOB_NUM.\$PBS_ARRAY_INDEX \$dir_path/\$PBS_JOBNAME.o\$JA_JOB_NUM.\$PBS_ARRAY_INDEX" >> $1
   fi
}


function finish_jobarray_and_scratch {
   if [ -n "$PBS_JOB_ARRAY_RANGE" ]
   then
      if [ -n "$SCRATCH_TYPE" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
	 then
            echo "rsync -a --exclude INCAR --exclude POTCAR --exclude POSCAR --exclude KPOINTS . \$dir_path" >> $1
	 else
            echo "rsync -a --exclude \$input_name . \$dir_path" >> $1
	 fi
      fi
      echo "rm \$dir_path/\$PBS_JOBNAME.o\$JA_JOB_NUM.\$PBS_ARRAY_INDEX" >> $1
      echo "mv \$HOME/\$PBS_JOBNAME.o\$JA_JOB_NUM.\$PBS_ARRAY_INDEX \$dir_path/\$PBS_JOBNAME.o\$JA_JOB_NUM.\$PBS_ARRAY_INDEX" >> $1
   else
      if [ -n "$SCRATCH_TYPE" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
	 then
            echo "rsync -a --exclude INCAR --exclude POTCAR --exclude POSCAR --exclude KPOINTS . \$PBS_O_WORKDIR" >> $1
	 else
            echo "rsync -a --exclude $INPUT . \$PBS_O_WORKDIR" >> $1
         fi
      fi
      echo "#" >> $1
      echo "if [ \$PBS_O_WORKDIR != \$HOME ]" >> $1
      echo "then" >> $1
      echo "rm \$PBS_O_WORKDIR/\$PBS_JOBNAME.o\$JOB_NUM" >> $1
      echo "mv \$HOME/\$PBS_JOBNAME.o\$JOB_NUM \$PBS_O_WORKDIR/\$PBS_JOBNAME.o\$JOB_NUM" >> $1
      echo "fi" >> $1
   fi
   if [ -n "$SCRATCH_TYPE" ]
   then
      if [ $SCRATCH_TYPE != "scratch" ]
      then
         echo "for host in \`uniq \$PBS_NODEFILE\`" >> $1
         echo "do" >> $1
         echo "ssh \$host rm -R $SCRATCH_BASE_DIR/\$\$" >> $1
         echo "done" >> $1
      else
         echo "rm -R $SCRATCH_BASE_DIR/\$\$" >> $1
         if [ -n "$PBS_JOB_ARRAY_RANGE" ]
         then
            echo "rm \$dir_path/\$\$" >> $1
         else
            echo "rm \$PBS_O_WORKDIR/\$\$" >> $1
         fi
      fi
   fi
}


function slurm_finish_jobarray_and_scratch {
   if [ -n "$JOB_ARRAY_RANGE" ]
   then
      if [ -n "$SCRATCH_TYPE" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
	 then
            echo "rsync -a --exclude INCAR --exclude POTCAR --exclude POSCAR --exclude KPOINTS . \$dir_path" >> $1
	 else
            echo "rsync -a --exclude \$input_name . \$dir_path" >> $1
	 fi
      fi
   else
      if [ -n "$SCRATCH_TYPE" ]
      then
         if [ "$EXE_NAME" == "vasp" ]
	 then
            echo "rsync -a --exclude INCAR --exclude POTCAR --exclude POSCAR --exclude KPOINTS . \$SLURM_SUBMIT_DIR" >> $1
	 else
            echo "rsync -a --exclude $INPUT . \$SLURM_SUBMIT_DIR" >> $1
         fi
      fi
      echo "#" >> $1
#      echo "if [ \$PBS_O_WORKDIR != \$HOME ]" >> $1
#      echo "then" >> $1
#      echo "rm \$PBS_O_WORKDIR/\$PBS_JOBNAME.o\$JOB_NUM" >> $1
#      echo "mv \$HOME/\$PBS_JOBNAME.o\$JOB_NUM \$PBS_O_WORKDIR/\$PBS_JOBNAME.o\$JOB_NUM" >> $1
#      echo "fi" >> $1
   fi
   if [ -n "$SCRATCH_TYPE" ]
   then
      if [ $SCRATCH_TYPE != "scratch" ]
      then
         echo "for host in \`uniq \$SLURM_NODEFILE\`" >> $1
         echo "do" >> $1
         echo "ssh \$host rm -R $SCRATCH_BASE_DIR/\$\$" >> $1
         echo "done" >> $1
      else
         echo "rm -R $SCRATCH_BASE_DIR/\$\$" >> $1
         if [ -n "$JOB_ARRAY_RANGE" ]
         then
            echo "rm \$dir_path/\$\$" >> $1
         else
            echo "rm \$SLURM_SUBMIT_DIR/\$\$" >> $1
         fi
      fi
   fi
}


function calc_chunk_new {
  if [ -z $MPI_PER_NODE_SET ]
  then
     if [ $XTRA_MEM -eq 1 ]
     then
        MPIPROCS=$(($MPIPROCS - 1))
     fi
     NNODES=$MPIPROCS
     RPROCS1=1
     NCPUS=1
  else
     if [ $CPU_TYPE == "broadwell" ]
     then
        CORES_PER_NODE=36
        if [ -z $MPI_PER_NODE_SET ]
        then
           MPI_PER_NODE=$CORES_PER_NODE 
        fi
     fi
     if [ $XTRA_MEM -eq 1 ]
     then
        MPIPROCS=$(($MPIPROCS - 1))
     fi
#     TOTAL_PROCS=$(($MPIPROCS * $OMPTHREADS))
     TOTAL_PROCS=$MPIPROCS
#     echo "TOTAL_PROCS = $TOTAL_PROCS"
     NNODES=`expr $TOTAL_PROCS / $MPI_PER_NODE`
     DIV_BY_CORES_PER_NODE=`expr $TOTAL_PROCS % $CORES_PER_NODE`
     MOD_BY_MPI_PER_NODE=`expr $TOTAL_PROCS % $MPI_PER_NODE`
     STR1=""
     STR2=""
#  if [ $DIV_BY_CORES_PER_NODE -ne 0 ]
#  then
#    STR1="Warning: You have requested $TOTAL_PROCS mpi processes, it would be more efficient to"
#    STR2="         request mpi processes in multiples of $CORES_PER_NODE."
##    echo "Warning: You have requested $1 mpi processes, it would be more efficient (on Fission) to"
##    echo "         request mpi processes in multiples of 32."
#  fi
     if [ $TOTAL_PROCS -le $CORES_PER_NODE -a $MPI_PER_NODE -eq $CORES_PER_NODE ]
     then
        NNODES=1
        RPROCS1=$MPIPROCS
     elif [ $MOD_BY_MPI_PER_NODE -eq 0 ]
     then
        RPROCS1=`expr $MPIPROCS / $NNODES`
     else
        RPROCS1=$MPI_PER_NODE 
        TMP2=$(($RPROCS1 * $NNODES))
        RPROCS2=`expr $MPIPROCS - $TMP2`
     fi
     NCPUS=$CORES_PER_NODE
     fi
#  echo "NNODES = $NNODES RPROCS1 = $RPROCS1  RPROCS2 = $RPROCS2"
#  echo "MOD_BY_MPI_PER_NODE = $MOD_BY_MPI_PER_NODE"
}


function get_ramdisk_size {
   if [ $CLUSTER == "falcon" ]
   then
      RAMDISK_SIZE=100
   elif [ $CLUSTER == "fission" ]
   then
      RAMDISK_SIZE=48
   elif [ $CLUSTER == "bechler" ]
   then
      RAMDISK_SIZE=12
   fi
}


function get_localdisk_size {
   if [ $CLUSTER == "bechler" ]
   then
      LOCALDISK_SIZE=250
   elif [ $CLUSTER == "quark" ]
   then
      LOCALDISK_SIZE=100
   else
      echo "Error: localdisk not available on $CLUSTER"
      exit 1
   fi
}


function get_scratch_dir {
   if [ $1 == "scratch" ]
   then
      SCRATCH_BASE_DIR="/scratch/$LOGNAME"
   elif [ $1 == "ramdisk" ]
   then
      if [ $CLUSTER == "bechler" ]
      then
         SCRATCH_BASE_DIR="/dev/shm"
      else
         SCRATCH_BASE_DIR="/tmp"
      fi
      get_ramdisk_size
      echo
      echo "Warning: You have requested to run your job in ramdisk."
      echo "Warning: $CLUSTER has $RAMDISK_SIZE GB of ramdisk space available on each Compute Node."
      echo "Warning: Make sure your job (temporary files, resulting/output files etc) can fit in this space or else the node will go down and your job will crash."
      echo
   elif [ $1 == "localdisk" ]
   then
      if [ $CLUSTER == "bechler" ]
      then
         SCRATCH_BASE_DIR="/tmp"
      else
         echo "Error: localdisk not available on $CLUSTER"
         exit 1
      fi
      get_localdisk_size
      echo
      echo "Warning: You have requested to run your job in localdisk."
      echo "Warning: $CLUSTER has $LOCALDISK_SIZE GB of ramdisk space available on each Compute Node."
      echo "Warning: Make sure your job (temporary files, resulting/output files etc) can fit in this space or else the node may go down and your job will crash."
      echo
   fi
}

