.SUFFIXES :
.PHONY : clean, mrproper

CXX = g++
FDMAP = -c
FLAG = -pedantic -Wall -std=c++11

run : main.o DoctorManager.o Doctor.o PrintManager.o Print.o Attribute.o QualitativeAttribute.o QuantitativeAttribute.o Disease.o DiseaseManager.o Measurement.o QualitativeMeasurement.o QuantitativeMeasurement.o FileReader.o FileWriter.o ServicesManager.o PrintAnalyzer.o
	$(CXX) $(FLAG) $^ -o $@ -g


main.o : models/PrintManager.h services/ServicesManager.h
DoctorManager.o : models/Doctor.h fileOperations/FileReader.h fileOperations/FileWriter.h
PrintManager.o : models/Print.h models/Attribute.h fileOperations/FileReader.h fileOperations/FileWriter.h
Print.o : models/Attribute.h
DiseaseManager.o : models/Disease.h models/Measurement.h models/PrintManager.h fileOperations/FileReader.h fileOperations/FileWriter.h
Disease.o : models/Measurement.h
FileReader.o : models/Attribute.h models/QualitativeAttribute.h models/QuantitativeAttribute.h
FileWriter.o : models/Print.h models/Doctor.h models/Disease.h
ServicesManager.o : models/Doctor.h models/DoctorManager.h models/PrintManager.h models/DiseaseManager.h services/PrintAnalyzer.h
PrintAnalyzer.o : models/Disease.h models/Print.h
QualitativeAttribute.o : models/Attribute.h
QuantitativeAttribute.o : models/Attribute.h
Measurement.o : models/Print.h
QuantitativeMeasurement.o = models/Measurement.h
QualitativeMeasurement.o = models/Measurement.h

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
	rm -rf run
