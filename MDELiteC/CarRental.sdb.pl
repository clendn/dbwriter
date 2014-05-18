:-style_check(-discontiguous).

table(class,[id,"name","fields","methods",superid]).
class(classnode0,'customer','','',null).
class(classnode1,'receipt','','',null).
class(classnode2,'contract','','',null).
class(classnode3,'CarRentalCompany','','',null).
class(classnode4,'RentalCar','','',null).

table(association,[cid1,"role1",arrow1,cid2,"role2",arrow2]).
association(classnode0,'1','comp',classnode2,'*','').
association(classnode0,'1','comp',classnode1,'paid','').
association(classnode2,'1','comp',classnode1,'0..1','').
association(classnode2,'1','',classnode4,'1','comp').
association(classnode3,'1 belongs_to','',classnode4,'* owns','arrow').
association(classnode3,'*','',classnode0,'*','').

table(interface,[id,"name","methods"]).
interface(unconnected0,'Don','').

table(classImplements,[cid,iid]).
:- dynamic classImplements/2.

table(interfaceExtends,[id,idx]).
:- dynamic interfaceExtends/2.

table(position,[id,x,y]).
position(classnode0,433,168).
position(classnode1,824,168).
position(classnode2,825,369).
position(classnode3,420,363).
position(classnode4,425,509).
position(unconnected0,830,519).

