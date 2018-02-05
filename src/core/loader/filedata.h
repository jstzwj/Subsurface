#ifndef FILEDATA_H
#define FILEDATA_H

#include <string>

namespace subsurface
{
    namespace loader
    {
        class FileData
        {
        public:
            FileData();
            // MainContext main;
            // UserSettings userSettings;
            std::string filename;
        };
    }
}


#endif // FILEDATA_H
