#include <cstdio>
#include "cstdlib"
#include "map"
#include "string"
#include "cstring"

int main(int argn, char** argc) {

    char *jvmHome = getenv("JVM_HOME");
    if (jvmHome == nullptr) {
        printf("Set environment variable JVM_HOME firstly.\n");
        return 0;
    }

    FILE *fp = fopen(strcat(jvmHome, "\\jvs"), "r");
    if (fp == nullptr) {
        printf("Can not open file: jvs.\n");
        return 0;
    }

    std::map<std::string, std::string> map;
    while (!feof(fp)) {
        char *line = new char[64 + 256];

        fscanf(fp, "%s\n", line);
        std::string strLine = line;
        delete[] line;

        size_t splitPos = strLine.find('-');
        std::string name = strLine.substr(0, splitPos);
        std::string path = strLine.substr(splitPos + 1, strLine.length());
        map[name] = path;
    }


    if (argn <= 1) {
        printf("Parameter must more then 1.\n");
        return 0;
    }

    std::string targetName = argc[1];
    std::string targetPath = map[targetName];
    if (targetPath.empty()) {
        printf("Not exist %s.\n", targetName.data());
        return 0;
    }
    std::string cmd = "setx JAVA_HOME " + targetPath +" /m";
    system(cmd.c_str());

    return 0;
}
