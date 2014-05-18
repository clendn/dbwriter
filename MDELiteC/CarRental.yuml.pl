:-style_check(-discontiguous).

table(yumlClass,[id,"name","fields","methods"]).
yumlClass(classnode0,'customer','','').
yumlClass(classnode1,'receipt','','').
yumlClass(classnode2,'contract','','').
yumlClass(classnode3,'CarRentalCompany','','').
yumlClass(classnode4,'RentalCar','','').

table(yumlInterface,[id,"name","methods"]).
yumlInterface(unconnected0,'Don','').

table(yumlAssociation,["name1","role1","end1","name2","role2","end2"]).
yumlAssociation('customer','1','++','contract','*','').
yumlAssociation('customer','1','++','receipt','paid','').
yumlAssociation('contract','1','++','receipt','0..1','').
yumlAssociation('contract','1','','RentalCar','1','++').
yumlAssociation('CarRentalCompany','1 belongs_to','','RentalCar','* owns','>').
yumlAssociation('CarRentalCompany','*','','customer','*','').

