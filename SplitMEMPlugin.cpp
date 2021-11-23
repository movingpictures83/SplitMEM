#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SplitMEMPlugin.h"

void SplitMEMPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void SplitMEMPlugin::run() {
}


void SplitMEMPlugin::output(std::string file) {
 std::string outputfile = file;
std::string myCommand = "";
//splitMEM -file ecoli_1kbp.fa -mem 10 -cdg ecoli_1kb.dot >& ecoli_1kb.log
myCommand += "splitMEM -file "+std::string(PluginManager::prefix())+parameters["fasta"]+" -mem "+parameters["mem"]+" -cdg "+outputfile;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<SplitMEMPlugin> SplitMEMPluginProxy = PluginProxy<SplitMEMPlugin>("SplitMEM", PluginManager::getInstance());
