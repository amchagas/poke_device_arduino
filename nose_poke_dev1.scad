platex = 76;
platey = 41;
platez = 1.8;


outterx = 23;
outtery = 23;
outterz = 20;

putInMiddle = 2;

innerx = outterx-putInMiddle;
innery = outtery-putInMiddle;
innerz = outterz+putInMiddle;

$fn=80;

module empty_cube(){

difference(){
difference(){
cube([outterx,outtery,outterz],center = true);
cube([innerx,innery,innerz],center = true);
}

translate([0,15,-4]){
rotate([90,0,0]){

cylinder(10,2.5,2.5);}}

translate([0,-10,-3]){
cube([4.85,6,6],center = true);}}
}

module hole(){
cube([outterx,outterx,outterz+1],center = true);
}

union(){
difference(){
cube([platex,platey,platez],center = true);
hole();}

translate([0,0,(outterz/2)-0.9]){empty_cube();}
}