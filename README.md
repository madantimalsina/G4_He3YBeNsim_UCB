# G4_He3YBeNsim_UCB
#Geant4 Simulation for LZ YBe Photoneutron source
 #To run example
 
 mkdir Build
 
 cd Build
 
cmake -DGeant4_DIR=/Users/.../Geant4.10/geant4.10.05-install/lib/Geant4-10.5.0/ ../G4_He3YBeNsim_UCB

make -j2


// it creat dependencies of target myHe3

// submit job

./myHe3 -m YBe_NewGenerator.mac
