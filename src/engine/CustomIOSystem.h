//
//  Author: Shervin Aflatooni
//

#ifndef CUSTOM_IO_SYSTEM
#define CUSTOM_IO_SYSTEM

#include <assimp/IOSystem.hpp>

class CustomIOSystem : public Assimp::IOSystem
{
public:
  CustomIOSystem(void);
  ~CustomIOSystem(void);

  bool ComparePaths (const char *one, const char *second) const;
  bool Exists(const char* pFile) const;
  char getOsSeparator(void) const;
  Assimp::IOStream *Open(const char* pFile, const char* pMode);
  void Close(Assimp::IOStream* pFile);
};

#endif
