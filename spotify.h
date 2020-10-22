#ifndef SPOTIFY_H
#define SPOTIFY_H

#include "cancion.h"

class Spotify
{
private:
    Cancion favoritos[50];
    size_t cont;

public:
    Spotify();
    void agregarFavoritos(const Cancion &cancion);
    void mostrar();
    void respaldar();
    void recuperar();
};

#endif // SPOTIFY_H
