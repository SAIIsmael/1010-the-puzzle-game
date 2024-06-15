#include <unistd.h>
#include "window.h"
#include "myprogram.h"

using namespace std;


int main (int argc,char *argv[]){
  char tmp;

  if(argc == 1){
    set_pseudo();
    startProgramX();  
    myprogram();
    stopProgramX();
  }


   while((tmp=getopt(argc,argv,"hnvp:"))!=-1){
    switch(tmp){
     
      case 'h':
      /* option help : règles du jeu*/
        cout<<"Règles du jeu :"<<endl;
        cout<<""<<endl;
        cout<<"L'objectif du jeu est de poser un maximum de pièces afin de récolter le plus de points"<<endl;
        cout<<"Il est bien évident que l'on pose despièces uniquement sur les espaces libres duplateau de jeu, le chevauchement de pièces est interdit"<<endl;
        cout<<"Le comptage des points se fait en fonction du nombre de lignes ou de colonnes que l'on supprime lorsque l'on pose une pièce"<<endl;
        cout<<"Le nombre de points gagnés se fait en fonction du nombre de lignes ou de colonnes que l'on détruit"<<endl;  
      break;

      /*option n : affiche les noms et prénoms des programmeurs*/ 
      case 'n':        
        cout<<"Programme crée par :"<<endl;
        cout<<""<<endl;
        cout<<"DAVIAUD DEMAILLE Julien"<<endl;
        cout<<"DEDEBANT Louis"<<endl;
        cout<<"SAI Ismael"<<endl;
        cout<<"HERRERO Yannick"<<endl;
      break;

      /*option p : modifie les shapes avec le fichier passe en argument*/
      case 'p':
        set_shapes(optarg);
        set_pseudo();
        startProgramX();
        myprogram();
        stopProgramX();
      break;

      /*option v: affiche la version du jeu*/
      case 'v':
        cout<<"Projet 1010 - v.1.0.4"<<endl;
      break;
      
      /*invail input will get the heil infomation*/
      default:
        cout<<""<<endl;
        cout<<"Options existantes: "<<endl;
        cout<<"-v (version du jeu)"<<endl;
        cout<<"-n (nom des programmeurs)"<<endl;
        cout<<"-h (aide)"<<endl;
      break;
    }
  }
  return 0;
}