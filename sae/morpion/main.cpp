#include <iostream>
#include <vector>

using namespace std;


unsigned int testLigne(vector<vector<char>> & tab)
{
    unsigned int pj2=0,pj1=0;
    for(size_t i=0;i<3;++i)
    {
        for(size_t j=0;j<3;++j)
        {
            if (j==2)break;
            if(tab[i][j] == tab[i][j+1])
            {
                if (tab[i][j] == 'o')
                {
                    pj1 += 1;
                }
                else if(tab[i][j] == 'x')
                {
                    pj2 += 1;
                }
            }
            else if(tab[i][j] != tab[i][j+1])
            {
                pj1 = 0;
                pj2 = 0;
            }
        }
    }
    if (pj1 == 2)
    {
        return 1;
    }
    else if (pj2 == 2)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


unsigned int testColonne(vector<vector<char>> & tab)
{
    unsigned int pj2=0,pj1=0;
    for(size_t j=0;j<3;++j)
    {
        for(size_t i=0;i<3;++i)
        {
            if (i==2)break;
            if(tab[i][j] == tab[i+1][j])
            {
                if (tab[i][j] == 'o')
                {
                    pj1 += 1;
                }
                else if(tab[i][j] == 'x')
                {
                    pj2 += 1;
                }
            }
            else if(tab[i][j] != tab[i+1][j])
            {
                pj1 = 0;
                pj2 = 0;
            }
        }
    }
    if(pj1 == 2)
    {
        return 1;
    }
    else if (pj2 == 2)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

}
vector<vector<int>> jouer(vector<vector<int>> tab)
{
    int i=5;
    int j;
    bool j1=true,j2=false,n;
    while(gagne(tab) == True)
    {
        cout << "entrez la colonne souhaité" << endl;
        cin >> j;

        if (test(tab,j) == 6) {
            cout<< " la colone est remplis";
        }
        if (test(tab,j) <6 ) {
            if(j1 == true)
            {
                tab[i][j] = 1;
            }
            else
            {
                tab[i][j] = 2;
            }
            j1=n;
            j1 = j2;
            j2=n;
        }

    }

}

unsigned int testDiago(vector<vector<char>> & tab)
{
    if (((tab[0][0] == tab[1][1]) && (tab[0][0] == tab[2][2])) || ((tab[0][2] == tab[1][1]) &&  (tab[0][2]== tab[2][0])))
    {
        if(tab[0][0] == 'o'|| tab[0][2] == 'o')
        {
            return 1;
        }
        else if(tab[0][0] == 'x'|| tab[0][2] == 'x')
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }

}

void affiche(vector<vector<char>> tableau){
    for(size_t i=0 ; i < 3 ;i=i+1 ){
        cout << endl ;
        for(size_t j=0 ; j < 3 ;++j ){
            cout <<tableau[i][j] << ".___|" ;
        }

    }

}
vector<vector<char>> remplir(vector<vector<char>> tab,char valeur,unsigned int position1,unsigned int position2){
    for(size_t i=0 ; i < 3 ;i=i+1 ){
        cout << endl ;
        for(size_t j=0 ; j < 3 ;++j ){
            if(i == position1 && j == position2){
            tab[i][j]=valeur ;
            }
        }

    }
    return tab;
}


bool isrempli(vector<vector<char>> tab){
    bool estrempli;
    for(size_t i=0 ; i < 3 ;i=i+1 ){
        cout << endl ;
        for(size_t j=0 ; j < 3 ;++j ){
            if(tab[i][j] == )
        }

    }
}
int main()
{
    vector<vector<char>> tab (3, vector<char> (3));
    vector<vector<char>> nouveau(3, vector<char> (3));
    char j1='o';
    char j2='X';
    unsigned int position1,position2;
    unsigned int compteur=0;
    while(true){
    cout << endl;
    cout << "joueur choisissez la position" << endl;
    cin >> position1;
    cin >> position2;
    compteur=compteur+1;
    tab=nouveau;
    if(compteur%2 != 0){
            tab=remplir(tab,j1,position1,position2);
            affiche(tab);
            nouveau=tab;
    }
    else
    {
       tab=remplir(tab,j2,position1,position2);
       affiche(tab);
       nouveau=tab;

    }
    if(isgagner(tab,j1) == true || isgagner2(tab,j2) == true){
       break;
    }
    }

    return 0;
}
