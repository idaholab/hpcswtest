/*

Copyright 2017 Battelle Energy Alliance, LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Description
-----------
HPC Software testing suite.
HeliosTest subclass source code.

Date Created: Wed Dec 23 13:20:23 MST 2015

Author: Cormac Garvey

*/

#include "heliostest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> HeliosTest::helios_aurora_03_inputs_ = {
R"(+SET management.
!/////////////////////////////////////////////////////////////////////////////!
!                     Expert input sets for AURORA                            !
!/////////////////////////////////////////////////////////////////////////////!

           ! First a set with some frequently used materials !
           ! =============================================== !

&ADD      = SET ( 'aurora-03.hrf' / SAMPLE; AURORA; &MAT )

'H2O-300' = MAT ( 0.9961/  1001, 11.19; 8016, 88.81 )            !H2O at 300 K!
'H2O-400' = MAT ( 0.9378/  1001, 11.19; 8016, 88.81 )            !H2O at 400 K!
'H2O-500' = MAT ( 0.8309/  1001, 11.19; 8016, 88.81 )            !H2O at 500 K!
'H2O-550' = MAT ( 0.7595/  1001, 11.19; 8016, 88.81 )            !H2O at 550 K!

 Zr       = MAT (       / 40002, 4.292E-2 )                      !Zircaloy!
 Steel    = MAT (  7.9  / 26001, 100 )                           !Stainless!
 B4C      = MAT (  1.8  /  5000, 78.28; 6000, 21.72 )            !B carbide!

'U-det'   = MAT ( NB /  / 92235, 1E-10)                          !Detector U5!

'UO2-1.6' = MAT (   10  / 92235, 1.6;  92238, 98.4;   8001, 0 )  !1.6 wt UO2!
'UO2-1.8' = MAT (   10  / 92235, 1.8;  92238, 98.2;   8001, 0 )  !1.8 wt UO2!
'UO2-2.0' = MAT (   10  / 92235, 2.0;  92238, 98.0;   8001, 0 )  !2.0 wt UO2!
'UO2-2.2' = MAT (   10  / 92235, 2.2;  92238, 97.8;   8001, 0 )  !2.2 wt UO2!
'UO2-2.4' = MAT (   10  / 92235, 2.4;  92238, 97.6;   8001, 0 )  !2.4 wt UO2!
'UO2-2.6' = MAT (   10  / 92235, 2.6;  92238, 97.4;   8001, 0 )  !2.6 wt UO2!
'UO2-2.8' = MAT (   10  / 92235, 2.8;  92238, 97.2;   8001, 0 )  !2.8 wt UO2!
'UO2-3.0' = MAT (   10  / 92235, 3.0;  92238, 97.0;   8001, 0 )  !3.0 wt UO2!
'UO2-3.2' = MAT (   10  / 92235, 3.2;  92238, 96.8;   8001, 0 )  !3.2 wt UO2!

'UO2-BA'  = MAT ( !3 wt enriched UO2, with 3 wt Gd2O3 admixed!
                  /  92235, 6.563E-4;  92238, 0.0209527;   8001, 0.04471 ;
                     64154, 2.090E-5;  64155, 1.473E-4 ;  64156, 2.050E-4;
                     64157, 1.563E-4;  64158, 2.468E-4 )

                            ! And the albedo !
                            ! ============== !

 White    = ALB (1/1/1)        ! Diagonal, alb(i,i)=1, for neutrons and gammas!



  ! Now the parameters and preset input for the case 'BWR-4x4' !
  ! ========================================================== !

&ADD      = SET ( 'aurora-03.hrf' / SAMPLE; AURORA; &BWR )
&MAT      = SET ( 'aurora-03.hrf' / SAMPLE; AURORA )

$film     = PAR ( "($box-4*$p)/2"   )          !Coolant film in BWR!
$delw     = PAR ( "$wide/3"         )          !Wide gap mesh!
$deln     = PAR ( "$narrow/2"       )          !Narrow gap mesh!
$w1       = PAR ( "$film+$bwt"      )          !Film + box wall!
$w2       = PAR ( "$w1+$delw"       )          !Wide: 1st mesh line!
$w3       = PAR ( "$w2+$delw"       )          !Wide: 2nd mesh line!
$w4       = PAR ( "$w1+$wide"       )          !Wide: 3rd mesh line!
$n1       = PAR ( "$w1"             )          !Film + box wall!
$n2       = PAR ( "$n1+$deln"       )          !Narrow: 1st mesh line!
$n3       = PAR ( "$n1+$narrow"     )          !Narrow: 2nd mesh line!

$rdi      = PAR (  $deln            )          !Inner detector tube!
$rdo      = PAR (  $narrow          )          !Outer detector tube!

$c1       = PAR ( "$delw"           )          !Centre piece: 1st mesh line!
$c2       = PAR ( "2*$delw"         )          !Centre piece: 2nd mesh line!
$c3       = PAR ( "3*$delw"         )          !Centre piece: 3rd mesh line!
$c4       = PAR ( "3*$delw+$w1"     )          !Centre piece: 4th mesh line!

$rab      = PAR ( "$delw"           )          !Radius of absorber pin!
$wlong    = PAR ( "$w4+3*$p-$clong" )          !Length of control wing!
$aa       = PAR ( "$wlong/4"        )          !Absorber cell: pitch!
$d1       = PAR ( "$delw"           )          !Absorber cell: 1st mesh line!
$d2       = PAR ( "2*$delw"         )          !Absorber cell: 2nd mesh line!
$ac       = PAR ( "$aa/2"           )          !Absorber pin: centre!

wg        = STR ( !Wide gap side, including box and film!
                  (0,0)     (0,$w4)     ($p,$w4)     ($p,0)       !nodes  1- 4!
                            ("$p/2",0)                            !node   5   !
                  (0,$film) ("$p/2",$film) ($p,$film)             !nodes  6- 8!
                  (0,$w1)   ("$p/2",$w1)   ($p,$w1)               !nodes  9-11!
                  (0,$w2)   ("$p/2",$w2)   ($p,$w2)               !nodes 12-14!
                  (0,$w3)   ("$p/2",$w3)   ($p,$w3)               !nodes 15-17!
                            ("$p/2",$w4)                          !node  18   !
                  / 4,gap / /        1, 6, 7, 5,film;  5, 7, 8, 4,film;
                   6, 9,10, 7,box;   7,10,11, 8,box;   9,12,13,10,gap;
                  10,13,14,11,gap;  12,15,16,13,gap;  13,16,17,14,gap;
                  15, 2,18,16,gap )                      !Last is default, gap!

wgx       = STR ( !Reduced wide gap side, including box and film!
                  (0,0)     (0,$w2)     ($p,$w2)     ($p,0)       !nodes  1- 4!
                            ("$p/2",0)                            !node   5   !
                  (0,$film) ("$p/2",$film) ($p,$film)             !nodes  6- 8!
                  (0,$w1)   ("$p/2",$w1)   ($p,$w1)               !nodes  9-11!
                            ("$p/2",$w2)                          !node  12   !
                  / 4,gap / /        1, 6, 7, 5,film;  5, 7, 8, 4,film;
                   6, 9,10, 7,box;   7,10,11, 8,box;   9, 2,12,10,gap )
                                                         !Last is default, gap!

ng        = STR ( !Narrow gap side, including box and film!
                  (0,0)     (0,$n3)     ($p,$n3)     ($p,0)       !nodes  1- 4!
                            ("$p/2",0)                            !node   5   !
                  (0,$film) ("$p/2",$film) ($p,$film)             !nodes  6- 8!
                  (0,$n1)   ("$p/2",$n1)   ($p,$n1)               !nodes  9-11!
                  (0,$n2)   ("$p/2",$n2)   ($p,$n2)               !nodes 12-14!
                            ("$p/2",$n3)                          !node  15   !
                  / 4,gap / /        1, 6, 7, 5,film;  5, 7, 8, 4,film;
                   6, 9,10, 7,box;   7,10,11, 8,box;   9,12,13,10,gap;
                  10,13,14,11,gap;  12, 2,15,13,gap )    !Last is default, gap!

ww        = STR ( !Reduced wide-wide corner, including box and film!
                  (0,0)     (0,$w2)   ($w2,$w2) ($w2,0)           !nodes  1- 4!
                  ($film,0) ($w1,0)   (0,$film) ($film,$film)     !nodes  5- 8!
                  (0,$w1)   ($w1,$w1) ($w2,$w1) ($w1,$w2)         !nodes  9-12!
                  / 4,gap / /        1, 9,10, 6,box;   1, 7, 8, 5,film;
                   6,10,11, 4,gap;   9, 2,12,10,gap )    !Last is default, gap!

wn        = STR ( !Wide-narrow corner, including box and film!
                  (0,0)   (0,$w4)   ($n3,$w4) ($n3,0)             !nodes  1- 4!
                  ($film,0) ($n1,0) ($n2,0)                       !nodes  5- 7!
                  (0,$film) ($film,$film)                         !nodes  8- 9!
                  (0,$w1) ($n1,$w1) ($n2,$w1) ($n3,$w1)           !nodes 10-13!
                  (0,$w2) ($n1,$w2) ($n2,$w2) ($n3,$w2)           !nodes 14-17!
                  (0,$w3) ($n1,$w3) ($n2,$w3) ($n3,$w3)           !nodes 18-21!
                          ($n1,$w4) ($n2,$w4)                     !nodes 22-23!
                  / 4,gap / /        1,10,11, 6,box;   1, 8, 9, 5,film;
                   6,11,12, 7,gap;   7,12,13, 4,gap;  10,14,15,11,gap;
                  11,15,16,12,gap;  12,16,17,13,gap;  14,18,19,15,gap;
                  15,19,20,16,gap;  16,20,21,17,gap;  18, 2,22,19,gap;
                  19,22,23,20,gap )                      !Last is default, gap!

nw        = STR ( !Narrow-wide corner, including box and film!
                  (0,0)   (0,$n3)   ($w4,$n3) ($w4,0)             !nodes  1- 4!
                  ($film,0) ($w1,0) ($w2,0)   ($w3,0)             !nodes  5- 8!
                  (0,$film) ($film,$film)                         !nodes  9-10!
                  (0,$n1) ($w1,$n1) ($w2,$n1) ($w3,$n1) ($w4,$n1) !nodes 11-15!
                  (0,$n2) ($w1,$n2) ($w2,$n2) ($w3,$n2) ($w4,$n2) !nodes 16-20!
                          ($w1,$n3) ($w2,$n3) ($w3,$n3)           !nodes 21-23!
                  / 4,gap / /        1,11,12, 6,box;   1, 9,10, 5,film;
                   6,12,13, 7,gap;   7,13,14, 8,gap;   8,14,15, 4,gap;
                  11,16,17,12,gap;  12,17,18,13,gap;  13,18,19,14,gap;
                  14,19,20,15,gap;  16, 2,21,17,gap;  17,21,22,18,gap;
                  18,22,23,19,gap )                      !Last is default, gap!

nn        = STR ( !Narrow-narrow corner, including box, film and detector tube!
                  (0,0)   (0,$n3)   ($n3,$n3) ($n3,0)             !nodes  1- 4!
                  ($film,0) ($n1,0) ($n2,0)                       !nodes  5- 7!
                  (0,$film) ($film,$film)                         !nodes  8- 9!
                  (0,$n1) ($n1,$n1) ($n2,$n1) ($n3,$n1)           !nodes 10-13!
                  (0,$n2) ($n1,$n2)           ($n3,$n2)           !nodes 14-16!
                          ($n1,$n3) ($n2,$n3)                     !nodes 17-18!
                  / 4,gap / dpin ($n3,$n3) 2 /         1,10,11, 6,box;
                   1, 8, 9, 5,film;  6,11,12, 7,gap;   7,12,13, 4,gap;
                  10,14,15,11,gap;  14, 2,17,15,gap )    !Last is default, gap!

dpin      = CCS ( !Detector tube with inner and outer region!
                  $rdi, $rdo / / deti, deto)

cw        = STR ( !One absorber cell of a wing of the control element!
                  (0,0)     (0,$d2)   ($aa,$d2) ($aa,0)           !nodes  1- 4!
                  (0,$d1)   ($aa,$d1)                             !nodes  5- 6!
                  ($ac,$d1)   !Currently, this "tangential" node must be given!
                  / 4,blade / apin ($ac,$d2) 1 /
                  1,5,6,4,blade )                      !Last is default, blade!

apin      = CCS ( !One-region control pin of the control element!
                  $rab / / abs)

wing      = CNX ( !Wing of the control element!
                  cw,cw,cw,cw     / (1,3,4)0(2,2,1) /      !One space element!
                  (2,3,4)0(3,2,1) / (3,3,4)0(4,2,1) )         !because k=0!

cc        = STR ( !Centre piece of the control element!
                  (0,0)     (0,$clong)   ($c2,$clong)             !nodes  1- 3!
                  ($c2,$c2) ($clong,$c2) ($clong,0)               !nodes  4- 6!
                  ($c1,0)   ($c2,0)      ($c3,0)   ($c4,0)        !nodes  7-10!
                  (0,$c1)   ($c1,$c1)    ($c2,$c1) ($c3,$c1)      !nodes 11-14!
                  ($c4,$c1) ($clong,$c1)                          !nodes 15-16!
                  (0,$c2)   ($c1,$c2)    ($c3,$c2) ($c4,$c2)      !nodes 18-20!
                  (0,$c3)   ($c1,$c3)    ($c2,$c3)                !nodes 21-23!
                  (0,$c4)   ($c1,$c4)    ($c2,$c4) ($c1,$clong)   !nodes 24-27!
                  / 6,blade / /       1,11,12, 7,blade;  7,12,13, 8,blade;
                   8,13,14, 9,blade;  9,14,15,10,blade; 10,15,16, 6,blade;
                  11,17,18,12,blade; 12,18, 4,13,blade; 13, 4,19,14,blade;
                  14,19,20,15,blade; 15,20, 5,16,blade; 17,21,22,18,blade;
                  18,22,23, 4,blade; 21,24,25,22,blade; 22,25,26,23,blade;
                  24, 2,27,25,blade )                  !Last is default, blade!

$peri     = PAR ( !Periperal nodes in a cell with 4 coolant regions!
                  (0,0)      (0,$p)      ($p,$p)     ($p,0)
                  (0,"$p/2") ("$p/2",$p) ($p,"$p/2") ("$p/2",0) )

$cregs    = PAR ( !Defining 4 coolant regions in a pin cell!
                  1,5,9,12,8,cool; 5,2,6,10,9,cool; 6,3,7,11,10,cool )

$cell1    = PAR ( !Pin cell with 4 coolant regions (pin radius $rp1)!
                  $peri ("$p/2-$rp1","$p/2") ("$p/2","$p/2+$rp1")
                        ("$p/2+$rp1","$p/2") ("$p/2","$p/2-$rp1")
                        / 4,cool / pin1 ("$p/2","$p/2") / $cregs )

$cell2    = PAR ( !Pin cell with 4 coolant regions (pin radius $rp2)!
                  $peri ("$p/2-$rp2","$p/2") ("$p/2","$p/2+$rp2")
                        ("$p/2+$rp2","$p/2") ("$p/2","$p/2-$rp2")
                        / 4,cool / pin2 ("$p/2","$p/2") / $cregs )

$cell3    = PAR ( !Pin cell with 4 coolant regions (pin radius $rp3)!
                  $peri ("$p/2-$rp3","$p/2") ("$p/2","$p/2+$rp3")
                        ("$p/2+$rp3","$p/2") ("$p/2","$p/2-$rp3")
                        / 4,cool / pin3 ("$p/2","$p/2") / $cregs )

$cell4    = PAR ( !Pin cell with 4 coolant regions (pin radius $rp4)!
                  $peri ("$p/2-$rp4","$p/2") ("$p/2","$p/2+$rp4")
                        ("$p/2+$rp4","$p/2") ("$p/2","$p/2-$rp4")
                        / 4,cool / pin4 ("$p/2","$p/2") / $cregs )

$row      = PAR ( !Coupling of 6 structures, the first and last are the
                   wide and narrow gap sides, the others are pin cells.
                   Rotate the wide side by -pi/2, the narrow by pi/2!
                  (1,4,1)$k(2,2,1) / (2,3,4)$k(3,2,1) / (3,3,4)$k(4,2,1) /
                  (4,3,4)$k(5,2,1) / (5,3,4)$k(6,1,4) )

top       = CNX ( ww, wgx,wgx,wgx,wg, wn                 !Rotate 'ww' by -pi/2!
                  / (1,4,1)2(2,2,1) / (2,3,4)0(3,2,1) / (3,3,4)0(4,2,1)
                  / (4,3,4)2(5,12,1)/ (5,3,4)2(6,2,1) )

bot       = CNX ( nw, ng,ng,ng,ng, nn  !rotate 'nw' & 'ng' by pi; 'nn' by pi/2!
                  / (1,1,2)2(2,4,3) / (2,1,2)0(3,4,3) / (3,1,2)0(4,4,3)
                  / (4,1,2)0(5,4,3) / (5,1,2)2(6,1,4) )

row1      = CNX ( wgx, $prow1, ng / $row )
row2      = CNX ( wgx, $prow2, ng / $row )
row3      = CNX ( wgx, $prow3, ng / $row )
row4      = CNX ( wg,  $prow4, ng / $row )

system    = CNX ( top, row1,row2,row3,row4, bot, cc,wing,wing
               / (1-1,2)(1-6,4)$k(2-1,3)(2-6,2) / (2-1,2)(2-6,3)$k(3-1,3)(3-6,2)
               / (3-1,2)(3-6,3)$k(4-1,3)(4-6,2) /(4-1,2)(4-6,3)$k(5-1,14)(5-6,2)
               / (5-1,2)(5-6,3)$k(6-1,4)(6-6,2) /      (1-1,2,4)$k(7,20,26)
               /        (7,2,3)$k(8-1,2,1)      /        (7,5,6)$k(9-4,4,3) )

system    = NEWK( !Adjust corner-gap coupling to k=2!
                  2 / (1-1,1,2) (1-6,4,1) (6-1,4,1) (6-6,1,2) /
                  !Adjust inter-gap coupling to k=0 (wgx with wg gets k=2)!
                  0 / (2-1,1,2) (3-1,1,2)           !Left side! /
                  2 /                     (4-1,1,2) !Left side! /
                  0 / (2-6,3,4) (3-6,3,4) (4-6,3,4) !Right side! )

system    = BDRY( !Diagonal albedo all around!
                  (7,1,1) $k (White) )        !From "cc" corner to "cc" corner!

outside   = OVLM( 'H2O-550'/*-*-0-*/                       !Water outside pins!
                  Zr/*-*-0-box,*-*-*-clad/                 !Zr in box and clad!
                  Steel/*-*-*-deto/                    !Steel of detector tube!
                  'U-det'/*-*-*-deti )                   !U vapour in detector!
fuels     = OVLM( $fuels )                           !Fuel materials from User!
fake      = OVLM( 'H2O-550'/*-*-0-blade,*-*-*-abs )  !Water in control element!
true      = OVLM( Steel/*-*-0-blade/                 !Steel of control element!
                  B4C/*-*-apin-* )                   !B4C of the absorber pins!

mos1      = OVSM( outside,fuels,fake )                           !Uncontrolled!
mos2      = OVSM( mos1/true )                                      !Controlled!

dov40     = OVLD( 1.0/*-*-**/ 0.6/*-*-0-(cool,film) )                !40 void!
dov70     = OVLD( 1.0/*-*-**/ 0.3/*-*-0-(cool,film) )                !70 void!

dos40     = OVSD( dov40 )                                            !40 void!
dos70     = OVSD( dov70 )                                            !70 void!

tov1      = OVLT( $tcool/*-*-**/ $tfuel/*-*-*-fuel )
tos1      = OVST( tov1 )

v40u      = STAT( mos1, dos40, tos1, $pw )             !40 void, uncontrolled!
v40c      = STAT( mos2, dos40, tos1, $pw )             !40 void,   controlled!
v70u      = STAT( mos1, dos70, tos1, $pw )             !70 void, uncontrolled!

    ! Here begin the output operators, still in the same set !
    ! ====================================================== !

ng1       = GROUP(N/0 )
ng2       = GROUP(N/1.8,0 )
ngall     = GROUP(N/ )                                           !Fast fluence!
gg1       = GROUP(G/0 )                                           !Gamma smear!
gg5       = GROUP(G/4E6,3E6,2E6,1E6,0)                               !Detector!

All       = AREA( <*-*-**>     )
FuelMap   = AREA( *-*-*-<fuel> )
DetArea   = AREA( *-*-*-<deti> )                                     !Detector!
AllClad   = AREA( <*-*-*-clad> )                                 !Fast fluence!
AllBox    = AREA( <*-*-0-box>  )                                 !Fast fluence!

NW        = FACE( (cc,7,11) )
NE        = FACE( (top-wn,23,21) )
SE        = FACE( (bot-nn,18,16) )
SW        = FACE( (bot-nw,23,20) )
Nside     = FACE( (cc,1,2) (8-cw,2,3)
                  (top-(wg,wn),2,3) )
Eside     = FACE( (1-wn,3,4) (2-ng,2,3) (3-ng,2,3)
                  (4-ng,2,3) (5-ng,2,3) (6-nn,2,3) )
Sside     = FACE( (bot-(nw,ng),2,3) (bot-nn,3,4) )
Wside     = FACE( (cc,6,1) (9-cw,2,3)
                  (5-wg,2,3) (6-nw,3,4) )

XSset     = MACRO(ng2,All / dn,tr,fi,kf )
Maps      = MACRO(ng1,FuelMap / bu,kf )
DetGam    = MACRO(gg5,DetArea / )                                    !Detector!
EgAll     = MACRO(gg1,All / ed )                                  !Gamma smear!
EgFuel    = MACRO(gg1,FuelMap / ed )                              !Gamma smear!
FlClad    = MACRO(T/ ngall,AllClad / )                           !Fast fluence!
FlBox     = MACRO(T/ ngall,AllBox  / )                           !Fast fluence!

'1/v'     = MICRO(ng2,All/1/ab )
FuelIsos  = MICRO(ng1,FuelMap//ab,fi )
XeSm      = MICRO(ng1,FuelMap/54635,62649/ab )
DetNeu    = MICRO(ng1,DetArea/92235/fi )                             !Detector!

CurCorner = CUR ( ng2,NW,NE,SE,SW )                     !Discontinuity factors!
CurSide   = CUR ( ng2,Nside,Eside,Sside,Wside )         !Discontinuity factors!

!/////////////////////////////////////////////////////////////////////////////!
!                     Expert input sets for ZENITH                            !
!/////////////////////////////////////////////////////////////////////////////!

! -------------------------------------------------------- Common definitions !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &Common)
! --------------------------------------------------------------------------- !
C1       = IMP(HELIOS;$Hcase/ $Hfile)
Burnup   = SEL(uburn / status/ C1;   / $calp)
$mapsize = PAR(58;13)
                                             ! Compute the power distribution !
fx       = SEL(fx    / macro/ C1;Maps/ $calp)
kf       = SEL(kf    / macro/ C1;Maps/ $calp)
vo       = SEL(vo    / macro/ C1;Maps)
power    = FOR(fx*kf*vo)

! -------------------------------------------------- Macroscopic neutron data !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &Basic)
! --------------------------------------------------------------------------- !
'K-inf'  = SEL(kinf  / macro/ C1;XSset/ $calp)
'K-eff'  = SEL(eigv  / macro/ C1;XSset/ $calp)
'Mig-area' = SEL(msq / macro/ C1;XSset/ $calp)
'Crit-B2'  = SEL(bsq / macro/ C1;XSset/ $calp)

dr       = SEL(dr    / macro/ C1;XSset/ $calp)
tr       = SEL(tr    / macro/ C1;XSset/ $calp)
ab       = SEL(ab    / macro/ C1;XSset/ $calp)
fi       = SEL(fi    / macro/ C1;XSset/ $calp)
nf       = SEL(nf    / macro/ C1;XSset/ $calp)
kf       = SEL(kf    / macro/ C1;XSset/ $calp)
p0       = SEL(p0    / macro/ C1;XSset/ $calp)
fx       = SEL(fx    / macro/ C1;XSset/ $calp)

i1       = IND(ab    / RAN:;;;1;)
i2       = IND(ab    / RAN:;;;2;)
i12      = IND(p0    / RAN:;;;1;2)
i21      = IND(p0    / RAN:;;;2;1)

D1       = FOR((dr/(3*tr))^i1)
D2       = FOR((dr/(3*tr))^i2)
Abso1    = FOR(ab^i1)
Abso2    = FOR(ab^i2)
Fiss1    = FOR(fi^i1)
Fiss2    = FOR(fi^i2)
Nufi1    = FOR(nf^i1)
Nufi2    = FOR(nf^i2)
Remo1    = FOR((p0^i21)*Abso2/(Abso2+(p0^i12)))
Flux1    = FOR(fx^i1)
Flux2    = FOR(fx^i2)
'Reso esc prob'  = FOR(Remo1/(Remo1+Abso1))

Basic    = LIST(Burnup;S/
               'Path/tree name, state name, burnup, k-inf, k-eff';
               'migration area [cm2], critical buckling [cm-2] and';
               'resonance escape probability'
               /E/
                f5:'K-inf'; 'K-eff'; e5:'Mig-area'; 'Crit-B2';
                f5:'Reso esc prob')
XSdata   = LIST(Burnup;S/
               'Average macroscopic cross sections and fluxes (2 groups)';
               'Cutoff energy = 1.8 ev'
                /E/
                f5:D1; D2; e5:Abso1; Abso2; Remo1; Nufi1; Nufi2;
                              Fiss1; Fiss2; Flux1; Flux2 )

! ------------------------------------------------------------ Xe and Sm data !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &XenSam)
! --------------------------------------------------------------------------- !
nd       = SEL(nd    / micro/ C1;XeSm/ $calp)
nxe      = SEL(nd    / micro/ C1;XeSm/ $calp/ 54635)
nsm      = SEL(nd    / micro/ C1;XeSm/ $calp/ 62649)
axe      = SEL(ab    / micro/ C1;XeSm/ $calp/ 54635)
asm      = SEL(ab    / micro/ C1;XeSm/ $calp/ 62649)
fx       = SEL(fx    / micro/ C1;XeSm/ $calp)
vo       = SEL(vo    / micro/ C1;XeSm/ $calp)

fimac    = FOR(@smI(nd*fi))
avfxfi   = FOR(@smR(fx*fimac*vo)/@smR(vo))
avfxaxe  = FOR(@smR(fx*axe*vo)  /@smR(vo))
avfxasm  = FOR(@smR(fx*asm*vo)  /@smR(vo))
'N(Xe)'  = FOR(@smR(nxe*vo)     /@smR(vo))
'N(Sm)'  = FOR(@smR(nsm*vo)     /@smR(vo))
'Yield(Xe)'  = FOR(1E24*'N(Xe)'* (avfxaxe*1E-24 +2.1E-5) /avfxfi)
'Yield(Sm)'  = FOR(     'N(Sm)'*  avfxasm                /avfxfi)

XeSm     = LIST(Burnup;S/
           'Average number densities and fission yields for Xe-135 and Sm-149';
           'Number densities (N) in [at/barn-cm]';
           'Effective yield for Xe-135 calculated using lambda=2.1E-5 [seg-1]'
            /E/
            e5:'N(Xe)'; 'N(Sm)';'Yield(Xe)'; 'Yield(Sm)' )

! --------------------------------------- Max burnup, power and power density !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &MaxBuPow)
! --------------------------------------------------------------------------- !
bu       = SEL(bu    / macro/ C1;Maps    / $calp)
rho      = SEL(rho   / micro/ C1;FuelIsos/ $calp)

ip       = IND(bu / PER:RIEGO)
i1       = IND(bu / RAN:1;;;;)
is       = IND(bu / SOR:)
b1       = FOR(bu^is)
e1       = FOR(@nbE(bu)^is)
r1       = FOR(@nbR(bu)^is)
ia       = IND(e1   / SOR:ascen)
'Max burn' = FOR(((b1^ia)^^ip)^i1)
'at pin'   = FOR(((r1^ia)^^ip)^i1)

ip       = IND(power / PER:RIEGO)
i1       = IND(power / RAN:1;;;;)
is       = IND(power / SOR:)
p1       = FOR(power^is)
e1       = FOR(@nbE(power)^is)
r1       = FOR(@nbR(power)^is)
ia       = IND(e1   / SOR:ascen)
'Max W/cm' = FOR(((p1^ia)^^ip)^i1)
' at pin'  = FOR(((r1^ia)^^ip)^i1)

ipos     = IND(power / WIND:1.0E-20,/ 1.0)
rho      = FOR(((power*0+rho)^ipos)^^ipos)
powdens  = FOR(power/(rho*vo))
ip       = IND(powdens/ PER:RIEGO)
is       = IND(powdens/ SOR:)
p1       = FOR(powdens^is)
e1       = FOR(@nbE(powdens)^is)
r1       = FOR(@nbR(powdens)^is)
ia       = IND(e1   / SOR:ascen)
'Max W/gU' = FOR(((p1^ia)^^ip)^i1)
'  at pin' = FOR(((r1^ia)^^ip)^i1)

MaxVals  = LIST(Burnup;S/
               'Maximum burnup, power density [W/gU] and linear power [W/cm]';
               'Power peaking factor (ppf) without gamma smearing'
               /E/
               f0:'Max burn'     ;    'at pin'  ;
               f3:'Max W/gU'     ;f0: '  at pin';
               f3:'Max W/cm'     ;f0: ' at pin' ;
               f4: ppf     )

! -------------------------- Delayed neutron fractions and neutron velocities !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &DelayNeut)
! --------------------------------------------------------------------------- !
B1macro  = BONE(/C1:XSset)
sig1v    = SEL(ab    / micro/ C1;'1/v'   / $calp)
be       = SEL(be    / macro/   ;B1macro / $calp)

'1/v'    = FOR(sig1v/ 220000)
i1       = IND(be /RAN:;;;1;)
i2       = IND(be /RAN:;;;2;)
i3       = IND(be /RAN:;;;3;)
i4       = IND(be /RAN:;;;4;)
i5       = IND(be /RAN:;;;5;)
i6       = IND(be /RAN:;;;6;)
'Beta(1)'  = FOR(be^i1)
'Beta(2)'  = FOR(be^i2)
'Beta(3)'  = FOR(be^i3)
'Beta(4)'  = FOR(be^i4)
'Beta(5)'  = FOR(be^i5)
'Beta(6)'  = FOR(be^i6)
'Beta-tot' = FOR(@smG(be))

DelNeut  = LIST(Burnup/
          'Effective delayed neutron fractions and inverse neutron velocities';
          'Beta(i):  delayed neutron fraction in delayed neutron group "i"';
          'Beta-tot: integrated value over the 6 groups';
          '1/v:      inverse neutron velocities in sec/cm'
          /E/
          e5:'Beta(1)'; 'Beta(2)'; 'Beta(3)'; 'Beta(4)'; 'Beta(5)'; 'Beta(6)';
             'Beta-tot'; '1/v'   )

! -------------------------------------------------- Average fuel composition !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &AvFuel )
! --------------------------------------------------------------------------- !
$hiso    = PAR(92235; 92236; 92238; 94238; 94239; 94240; 94241; 94242)
$avo     = PAR(0.6023)
ndens    = SEL(nd    / micro/ C1;FuelIsos/ $calp/ $hiso)
aw       = SEL(aw    / micro/ C1;FuelIsos/ $calp/ $hiso)
rho      = SEL(rho   / micro/ C1;FuelIsos/ $calp)
vol      = SEL(vo    / micro/ C1;FuelIsos)

nd       = FOR(@smR(ndens*vol)/@smR(vol))
'g/cm'   = FOR(@smR(vol)*nd*aw/$avo)
'wt%'    = FOR(100 *'g/cm'/@smR(rho*vol))

iu5      = IND(nd /RAN:;1;;;)
iu6      = IND(nd /RAN:;2;;;)
iu8      = IND(nd /RAN:;3;;;)
ip8      = IND(nd /RAN:;4;;;)
ip9      = IND(nd /RAN:;5;;;)
ip0      = IND(nd /RAN:;6;;;)
ip1      = IND(nd /RAN:;7;;;)
ip2      = IND(nd /RAN:;8;;;)

U235     = FOR(nd^iu5)
U236     = FOR(nd^iu6)
U238     = FOR(nd^iu8)
Pu238    = FOR(nd^ip8)
Pu239    = FOR(nd^ip9)
Pu240    = FOR(nd^ip0)
Pu241    = FOR(nd^ip1)
Pu242    = FOR(nd^ip2)

InvNd    = LIST(Burnup;S/
               'Average fuel composition in at/barn-cm'
                /E/
                e5:U235; U236; U238; Pu238; Pu239; Pu240; Pu241; Pu242)

U235     = FOR('g/cm'^iu5)
U236     = FOR('g/cm'^iu6)
U238     = FOR('g/cm'^iu8)
Pu238    = FOR('g/cm'^ip8)
Pu239    = FOR('g/cm'^ip9)
Pu240    = FOR('g/cm'^ip0)
Pu241    = FOR('g/cm'^ip1)
Pu242    = FOR('g/cm'^ip2)

InvG     = LIST(Burnup;S/
               'Average fuel composition in g/cm'
                /E/
                f4:U235; U236; U238; Pu238; Pu239; Pu240; Pu241; Pu242)

U235     = FOR('wt%'^iu5)
U236     = FOR('wt%'^iu6)
U238     = FOR('wt%'^iu8)
Pu238    = FOR('wt%'^ip8)
Pu239    = FOR('wt%'^ip9)
Pu240    = FOR('wt%'^ip0)
Pu241    = FOR('wt%'^ip1)
Pu242    = FOR('wt%'^ip2)

InvRel   = LIST(Burnup;S/
               'Average fuel composition in weight % of initial heavy mass'
                /E/
                f4:U235; U236; U238; Pu238; Pu239; Pu240; Pu241; Pu242)

! --------------------------------------------------- Burnup and Power arrays !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &BuPow)
! --------------------------------------------------------------------------- !
burnup   = SEL(bu    / macro/ C1;Maps/ $calp)
cxfuel   = SEL(vx    / macro/ C1;Maps)
cyfuel   = SEL(vy    / macro/ C1;Maps)
nopins   = SEL(nra   / macro/ C1;Maps)

avpow    = FOR(@smR(power)/nopins)
'power peaking' = FOR(power/avpow)
ppf             = FOR(@mxR('power peaking'))

! ------------------------------------------------------- Gamma-smeared power !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &GammaSmear)
! --------------------------------------------------------------------------- !
Bugam    = SEL(uburn / macro/ C1;EgAll / $calpg)
TotGamPow= SEL(ed    / macro/ C1;EgAll / $calpg)
pingam   = SEL(ed    / macro/ C1;EgFuel/ $calpg)
fxaver   = SEL(fx    / macro/ C1;XSset / $calpg)
kfaver   = SEL(kf    / macro/ C1;XSset / $calpg)
fxpin    = SEL(fx    / macro/ C1;Maps  / $calpg)
kfpin    = SEL(kf    / macro/ C1;Maps  / $calpg)
cxfuel   = SEL(vx    / macro/ C1;Maps)
cyfuel   = SEL(vy    / macro/ C1;Maps)
nopins   = SEL(nra   / macro/ C1;Maps)

Factor   = FOR(1-TotGamPow/@smG(fxaver*kfaver))
'Gamma smeared pow' = FOR((fxpin*kfpin*Factor+pingam)*vo)

avpow    = FOR(@smR('Gamma smeared pow')/nopins)
'Gamma smeared pow peak' = FOR('Gamma smeared pow'/avpow)
'Gamma smeared ppf'      = FOR(@mxR('Gamma smeared pow peak'))

! ------------------------------------------------------------ Fuel isotopics !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &PinFuelIso)
! --------------------------------------------------------------------------- !
cx       = SEL(vx    / micro/ C1;FuelIsos)
cy       = SEL(vy    / micro/ C1;FuelIsos)
Volumes  = SEL(vo    / micro/ C1;FuelIsos)
Isotopes = SEL(id    / micro/ C1;FuelIsos//$Isos)
'N(fuelpin)' = SEL(nd/ micro/ C1;FuelIsos/ $calp / $Isos)

PinMap   = MAP(;24 /$mapsize /
               'Output for fuel isotopics per pin';
               'Map showing the fuel pin numbers and volumes'
               / cx; cy/   Volumes)

IsoList  = LIST(;S/
                'Fuel isotopics per pin';
                'List of isotope identifiers'  /I/
                 f0:Isotopes)

NdList   = LIST(Burnup /
                'Fuel isotopics per pin';
                'Number densities in atoms/barn-cm per fuel pin and isotope';
                'R-I-E-.-. indicates fuel pin R and isotope I'            /E/
                'N(fuelpin)')

! ------------------------------------------------ Fast fluence in box & clad !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &FastFluence)
! --------------------------------------------------------------------------- !
$ecut    = PAR(1.0E6)
tsec     = SEL(ptime / macro/ C1;FlBox / $calp)
fxbox    = SEL(fx    / macro/ C1;FlBox / $calp)
fxclad   = SEL(fx    / macro/ C1;FlClad/ $calp)
eh       = SEL(heg   / macro/ C1;FlClad)
el       = SEL(leg   / macro/ C1;FlClad)

f1       = FOR(@ln(eh/$ecut)/@ln(eh/(el+1E-20)))
i1       = IND(f1   /WIN:0.0,/ 0.0)
f2       = FOR((f1^i1)^^i1)
i2       = IND(f2   /WIN:-1.0,1.0/ 1.0)
f        = FOR((f2^i2)^^i2)
Box      = FOR(@spE(@smG(fxbox *f*tsec)))
Clad     = FOR(@spE(@smG(fxclad*f*tsec)))

Fluence  = LIST(Burnup;S/
                'Fast fluence (>1 Mev) in channel box and clad'
                 /E/
                 Box; Clad)

! ------------------------------------------------- Neutron detector response !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &NeutronDetect)
! --------------------------------------------------------------------------- !
fxdet    = SEL(fx    / micro/ C1;DetNeu/ $calp)
fidet    = SEL(fi    / micro/ C1;DetNeu/ $calp /92235)

NeuDet   = FOR(fxdet*fidet*1E-24)

NeutronD = LIST(Burnup;S/
               'Neutron detector response factors:';
               'NeuDet     : absolute fission rate in fissions/sec'
                /E/
                NeuDet)

! --------------------------------------------------- Gamma detector response !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &GammaDetect)
! --------------------------------------------------------------------------- !
DetResp  = ARRAY(G: 1.915; 1.862; 2.028; 2.870; 5.284)
Burgam   = SEL(uburn / macro/ C1;DetGam/ $calpg)
fxdet    = SEL(fx    / macro/ C1;DetGam/ $calpg)

GamDet   = FOR(@smG(fxdet*DetResp))

GammaD   = LIST(Burgam;S/
           'Gamma detector response factors:';
           'GamDet    : absolute ionization rate in ion-pairs/sec'
            /E/
            GamDet)

! ----------------------------------------------------- Discontinuity factors !
&ADD     = SET('aurora-03.hrf' / SAMPLE; ZENITH; &DiscFactors)
! --------------------------------------------------------------------------- !
fx       = SEL(fx    / macro/ C1;XSset    / $calp)
jpcor    = SEL(jp    / cur  / C1;CurCorner/ $calp)
jmcor    = SEL(jm    / cur  / C1;CurCorner/ $calp)
jpsid    = SEL(jp    / cur  / C1;CurSide  / $calp)
jmsid    = SEL(jm    / cur  / C1;CurSide  / $calp)

Corners  = FOR(2*(jpcor+jmcor)/fx)
Sides    = FOR(2*(jpsid+jmsid)/fx)

DisFact  = LIST(Burnup;;5/
                'Flux discontinuity factors';
                'f-.-E-g-. denotes face "f" and group "g"';
                'f=1 for NW corner and N side';
                'f=2 for NE corner and W side';
                'f=3 for SW corner and E side';
                'f=4 for SE corner and S side'
                 /E/
                 Corners ;; Sides)

  ! This terminates the presetting for a "short" BWR-4x4 input !
  ! ========================================================== !
)"
}; // vector helios_aurora_03_inputs_


const std::vector<std::string> HeliosTest::helios_aurora_31_inputs_ = {
R"(+HELIOS input (almost "short").

!%= aurora-03.hrf !

'BWR-4x4' = CASE( 'hy049n18g201.dat' / 'aurora-31.hrf' /
                  'BWR-4x4, T=550, v=40, cr=0, pw=25.1, br=70=40 (cr=1)' )

&BWR      = SET ( 'aurora-03.hrf' / SAMPLE; AURORA )                 !Read set!

pin1      = CCS ( 0.44, $rp1 // fuel,  clad )                        !Thin pin!
pin2      = CCS ( 0.50, $rp2 // fuel,  clad )                      !Normal pin!
pin3      = CCS ( 0.55, $rp3 // water, clad )                       !Water pin!
pin4      = CCS ( .20, .30, .35, .40, .45, .50, $rp4 //     !Burnable absorber!
                  fuel,fuel,fuel,fuel,fuel,fuel, clad )   !pin: 6 fuel regions!

'1.8'     = STR ( $cell1 )                                           !Thin pin!
'2.0'     = STR ( $cell1 )                                           !Thin pin!
'2.4'     = STR ( $cell2 )                                         !Normal pin!
'2.6'     = STR ( $cell2 )                                         !Normal pin!
'3.0'     = STR ( $cell2 )                                         !Normal pin!
WP        = STR ( $cell3 )                                          !Water pin!
BA        = STR ( $cell4 )                                  !Burnable absorber!

burn40    = PATH( / G, (v40u), 200, 500, 1000, 2000, 10 000/4, 26 000/4 )

branches  = TREE(burn40 / PG,(v70u), G,(v40c) /
                           500, 2000, 10 000/2, 22 000 )

$fuels    = PAR ( 'UO2-1.8' / *-'1.8'-*-fuel  /
                  'UO2-2.0' / *-'2.0'-*-fuel  /
                  'UO2-2.4' / *-'2.4'-*-fuel  /
                  'UO2-2.6' / *-'2.6'-*-fuel  /
                  'UO2-3.0' / *-'3.0'-*-fuel  /
                  'H2O-550' / *-  WP -*-water /
                  'UO2-BA'  / *-  BA -*-fuel  )

$prow1    = PAR ( '1.8',  '2.6',  '2.6',  '2.0' )
$prow2    = PAR ( '2.6',    BA ,  '3.0',  '2.4' )
$prow3    = PAR ( '2.6',  '3.0',    WP ,  '2.4' )
$prow4    = PAR ( '2.0',  '2.4',  '2.4',  '2.0' )

$k        = PAR ( 1 )           !Coupling!

$p        = PAR ( "1.5" )       !Pitch!
$box      = PAR ( "6.2" )       !Box, inner dimension!
$bwt      = PAR ( "0.1" )       !Box wall thickness!
$wide     = PAR ( "0.6" )       !Wide gap, half-width!
$narrow   = PAR ( "0.4" )       !Narrow gap, half-width!
$clong    = PAR ( "1.4" )       !Length of centre piece!
$rp1      = PAR ( "0.50" )      !Thin pin, clad radius!
$rp2      = PAR ( "0.56" )      !Normal pin, clad radius!
$rp3      = PAR ( "0.65" )      !Water pin, clad radius!
$rp4      = PAR ( "0.56" )      !BA pin, clad radius!
$tcool    = PAR ( 550 )         !Coolant temperature!
$tfuel    = PAR ( 925 )         !Fuel temperature!
$pw       = PAR ( 25.1 )        !Power level!

'BWR-4x4' = RUN ( OUT: 1 )
)"  // vector helios_aurora_31_inputs_
};


const std::vector<std::string> HeliosTest::helios_zenith_31_inputs_ = {
R"(!%=zenith-31.hrf
!%=aurora-03.hrf
!
BEGIN ('ZENITH sample case 02')
%OPTIONS(LINPAG=60)
 
!========================= Parameters for output sets ==========================
$Hcase  = PAR('BWR-4x4')                                 
$Hfile  = PAR('zenith-31.hrf')
$Path   = PAR(burn40)
$State  = PAR(v40u)
                                      
$Burnup = PAR(0,1000,2000-30000)
$Burgam = PAR(0,1000,2000-30000)

! -------------------------------- Options -------------------------------------
%'basic_output'      = 1
%'xenon_and_samarium'= 1
%'maximum_burn_power'= 1
%'delayed_neutrons'  = 1
%'neut_det_response' = 1
%'gamm_det_response' = 1
%'burnup_map'        = 1
%'power_maps'        = 1
%'gamma_smearing'    = 3
%'fast_fluence'      = 1
%'discont_factors'   = 1
%'av_fuel_isotopics' = 1
%'fuel_pin_isotopics'= 1
$Isos = PAR(92238; 94239)    
!===============================================================================
!     <<<<<<<<<<<<<<<<<<<<<< End of Users Input >>>>>>>>>>>>>>>>>>>>>>>>>      !
!===============================================================================
$calp     = PAR($Path:($State)$Burnup)
$calpg    = PAR($Path:($State)$Burgam)
&Common   = SET('aurora-03.hrf' / SAMPLE; ZENITH)
&BuPow    = SET('aurora-03.hrf' / SAMPLE; ZENITH)

%if ('basic_output'.eq.1)        then
&Basic    = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('maximum_burn_power'.eq.1)  then
&MaxBuPow  = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('gamma_smearing'.ne.0)      then
&GammaSmear = SET('aurora-03.hrf' / SAMPLE; ZENITH)
ppfGam  = LIST(Bugam;S/
           'Gamma smeared power peaking factor' /E/ 
            f4:'Gamma smeared ppf')
%end if

%if ('xenon_and_samarium'.eq.1)  then
&XenSam    = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('delayed_neutrons'.eq.1)    then
&DelayNeut = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('neut_det_response'.eq.1)   then
&NeutronDetect = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('gamm_det_response'.eq.1)   then
&GammaDetect = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('fast_fluence'.eq.1)        then
&FastFluence = SET('aurora-03.hrf' /SAMPLE; ZENITH)
%end if

%if ('discont_factors'.eq.1)     then
&DiscFactors = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('av_fuel_isotopics'.eq.1)   then
&AvFuel   = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('fuel_pin_isotopics'.eq.1)  then
&PinFuelIso   = SET('aurora-03.hrf' / SAMPLE; ZENITH)
%end if

%if ('burnup_map'.eq.1)          then
BuMap   = MAP(burnup; 25 /$mapsize/ 'Burnup distribution [Mwd/t]'
                                       / cxfuel; cyfuel/ burnup)
%end if

%if ('power_maps'.gt.0)          then
PPFMap  = MAP(fx; 15 /$mapsize/ 'Power peaking distribution'
                         / cxfuel; cyfuel/ 'power peaking')
%end if

%if ('power_maps'.gt.1)          then
PowMap  = MAP(fx; 15 /$mapsize/ 'Linear power distribution [W/cm]'
                                         / cxfuel; cyfuel/ power)
%end if

%if ('gamma_smearing'.ge.2)      then
PeakGam = MAP(fxpin; 15 /$mapsize/
             'Gamma smeared power peaking distribution'
            / cxfuel; cyfuel/ 'Gamma smeared pow peak')
%end if

%if ('gamma_smearing'.eq.3)      then
PowGam  = MAP(fxpin; 15 /$mapsize/
             'Gamma smeared linear power distribution [W/cm]'
                       / cxfuel; cyfuel/ 'Gamma smeared pow')
%end if

END()
)"
}; // vector helios_zenith_31_inputs_


std::string HeliosTest::getHeliosExeName(void) {
  return helios_exe_name_;
}


std::string HeliosTest::getAuroraExeName(void) {
  return aurora_exe_name_;
}


std::string HeliosTest::getZenithExeName(void) {
  return zenith_exe_name_;
}


HeliosTest::HeliosTest(const jobscript::PbsScript &p_s, const std::string &a_e_n, const std::string &h_e_n, const std::string &z_e_n, const std::string &h_t): AppTest(h_t, ".inp", p_s, helios_aurora_03_inputs_.size()),
                                                                                                                                                               log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                                                                                                               result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                                                                                                               flog_(log_file_name_,std::ios_base::app),
                                                                                                                                                               fresult_(result_file_name_,std::ios_base::app),
                                                                                                                                                               aurora_exe_name_(a_e_n),
                                                                                                                                                               helios_exe_name_(h_e_n),
                                                                                                                                                               zenith_exe_name_(z_e_n) {}


void HeliosTest::createHeliosPbs(jobscript::PbsScript &in_pbs) const {
//  jobscript::PbsScript out_pbs_local(in_pbs);
  in_pbs.setExeName(aurora_exe_name_);
  in_pbs.setExeArgs("aurora-03.inp;" + aurora_exe_name_ + " aurora-31.inp;" + "mv aurora-31.hrf helios-31.hrf;" + helios_exe_name_ + " helios-31.hrf;" + "mv helios-31.hrf zenith-31.hrf;" + zenith_exe_name_ + " zenith-31.inp");
}


void HeliosTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
  std::string helios_dir;
//  std::cout << "Execute runTest member function from HeliosTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  std::cout << "Testing: " << module_name_version(getPbsScripts()[0].getModules()[getPbsScripts()[0].getModules().size()-1]) << std::endl;
  int c_i = 0;
  for (auto helios_aurora_03_input: helios_aurora_03_inputs_) {
    helios_dir = "helios_" + std::to_string(getTestNumber()) + "_" + std::to_string(c_i);
    flog_ << "Run test in directory " << helios_dir << std::endl;
    makeDir(helios_dir);
    changeDir(helios_dir);
    jobscript::PbsScript helios_pbs(getPbsScripts()[c_i]); 
    copyFile("/hpc-common/software/sw_qa/scripts/hy049n18g201.dat","hy049n18g201.dat");
    createFileFromStr("aurora-03.inp", helios_aurora_03_input);
    createFileFromStr("aurora-31.inp", helios_aurora_31_inputs_[c_i]);
    createFileFromStr("zenith-31.inp", helios_zenith_31_inputs_[c_i]);
    createHeliosPbs(helios_pbs);
    fresult_ << module_name_version(getPbsScripts()[c_i].getModules()[getPbsScripts()[c_i].getModules().size()-1]) << "\t" << helios_dir << "\t" << getPbsScripts()[c_i].getJobName() << "\t" << "job." << std::endl;
    script_cmd_result = subPbsScript(flog_, helios_pbs);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    changeDir("..");
    ++c_i;
  }
}


} // namespace hpcswtest

