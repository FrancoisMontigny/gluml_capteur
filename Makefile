.SUFFIXES :
.PHONY : clean,mrproper

CXX = g++
FDMAP = -c
FLAG = -pedantic -Wall -std=c++11

test : main.o DoctorManager.o Doctor.o PrintManager.o Print.o Attribute.o QualitativeAttribute.o QuantitativeAttribute.o Disease.o DiseaseManager.o Measurement.o QualitativeMeasurement.o QualitativeMeasurement.o fileReader.o fileWriter.o ServicesManager.o PrintAnalyzer.o
	$(CXX) $(FLAG) $^ -o $@ -g


main.o : models/DoctorManager.h
DoctorManager.o : models/Doctor.h
PrintManager.o : models/Print.h
Print.o : models/Attribute.h
DiseaseManager.o : models/Disease.h models/Measurement.h
Disease.o : models/Measurement.h
fileReader.o : models/Attribute.h
fileWriter.o : models/Print.h models/Doctor.h
ServicesManager.o : models/Doctor.h models/DoctorManager.h
PrintAnalyzer.o : models/Disease.h models/Print.h

main.o : main.cpp
	$(CXX) $(FDMAP) $(FLAG) main.cpp

%.o : models/%.cpp
	$(CXX) $(FDMAP) $(FLAG) models/$*.cpp

%.o : fileOperations/%.cpp
	$(CXX) $(FDMAP) $(FLAG) fileOperations/$*.cpp

%.o: services/%.cpp
	$(CXX) $(FDMAP) $(FLAG) services/$*.cpp

#make clean pour supprimer les fichiers temporaires
clean :
	rm -rf *.o

#make mrproper && make pour supprimer avant de reconstruire 
mrproper : clean
	rm -rf test
