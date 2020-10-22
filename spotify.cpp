#include "spotify.h"
#include <fstream>

Spotify::Spotify()
{

}

void Spotify::agregarFavoritos(const Cancion &cancion)
{
    cont = 0;
    int i;
    if (cont < 50) {
        favoritos[cont++] = cancion;
        Cancion &cancion = favoritos[i];
    }
    else {
        cout << "Arreglo lleno" << endl;
    }
}

void Spotify::mostrar()
{
    cout << left;
    cout << setw(3) << "id";
    cout << setw(10) << "Titulo";
    cout << setw(10) << "Album";
    cout << setw(10) << "Artista";
    cout << setw(4) << "Duracion";
    cout << endl;

    for (size_t i = 0; i < cont; ++i) {
        cout << cancion << endl;
    }
}

void Spotify::respaldar()
{
    ofstream archivo("canciones.txt");
    if (archivo.is_open())
    {
        for (size_t i = 0; i < cont; i++)
        {
            Cancion &cancion = favoritos[i];
            archivo << cancion.getId() << endl;
            archivo << cancion.getTitulo() << endl;
            archivo << cancion.getAlbum() << endl;
            archivo << cancion.getArtista() << endl;
            archivo << cancion.getDuracion() << endl;
        }
        
    }
    archivo.close();
    
}

void Spotify::recuperar()
{
    ifstream archivo("canciones.txt");
    
    if (archivo.is_open())
    {
        
        Cancion cancion;
        string temp;
        double temp_d;
        temp_d = stod(temp);

        while (true)
        {
            getline(archivo, temp);           
            cancion.setId(temp);

            getline(archivo, temp);
            cancion.setTitulo(temp);

            getline(archivo, temp);
            cancion.setAlbum(temp);
            
            getline(archivo, temp);
            cancion.setArtista(temp);

            getline(archivo, temp);
            temp_d = stod(temp);
            cancion.setDuracion(temp_d);
        }
        if (archivo.eof()) 
		{
		break;
		}
    }
    
}