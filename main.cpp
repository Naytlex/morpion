#include <iostream>
#include <vector>

using namespace std;


unsigned int testLigne( vector<vector<char>> & tab)
{
    unsigned int pj2=0,pj1=0;
    for(unsigned int i=0;i<3;++i)
    {
        for(unsigned int j=0;j<3;++j)
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
    for(unsigned int j=0;j<3;++j)
    {
        for(unsigned int i=0;i<3;++i)
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
unsigned int gagne(vector<vector<char>> tab)
{
    if((testLigne(tab) == 0) && (testColonne(tab) == 0) && (testDiago(tab)==0))
    {
        return 0;
    }
    else if((testLigne(tab) == 1) || (testColonne(tab) == 1) || (testDiago(tab)==1))
    {
        return 1;
    }
    else if((testLigne(tab) == 2) || (testColonne(tab) == 2) || (testDiago(tab)==2 ))
    {
        return 2;
    }
}



void affiche(vector<vector<char>> tableau){
    for(unsigned int i=0 ; i < 3 ;i=i+1 ){
        cout << endl ;
        for(unsigned int j=0 ; j < 3 ;++j ){
            cout <<tableau[i][j] << ".___|" ;
        }

    }

}


bool isrempli(vector<vector<char>> tab)
{
    unsigned int cpt=0;
    for(unsigned int i=0;i<3;++i)
    {
        for(unsigned int j=0;j<3;++j)
        {
            if ((tab[i][j] == 'x') || (tab[i][j] == 'o'))
            {
                cpt += 1;
            }
        }
    }
    if (cpt == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void jouer(vector<vector<char>> tab)
{
    unsigned int l,c;
    bool j1=true,j2=false,n;
    while(gagne(tab) == 0)
    {
        cout << "entrez la colonne souhaité" << endl;
        cin >> c;
        cout << "entrez la ligne souhaité" << endl;
        cin >> l;

        while((tab[l][c] == 'x') || (tab[l][c] == 'o'))
        {
            cout<< " la case est deja remplis !";
            cout << "entrez la colonne souhaité" << endl;
            cin >> c;
            cout << "entrez la ligne souhaité" << endl;
            cin >> l;
        }
        if(j1 == true && j2 == false)
        {
            tab[l][c] = 'o';
        }
        else if(j2 == true && j1 == false)
        {
            tab[l][c] = 'x';
        }
        affiche(tab);
        if ( isrempli(tab) == true)
        {
            cout << "égalité";
            break;
        }
        n = j1;
        j1 = j2;
        j2=n;
    }
    if(gagne(tab) == 1)
    {
        cout << "le joueur 1 a gagné !" << endl;
    }
    else if(gagne(tab) == 2)
    {
        cout << "le joueur 2 a gagné ! " << endl;
    }
}

int main()
{
    vector<vector<char>> tab (3, vector<char> (3));
    affiche(tab);
    jouer(tab);

    return 0;
}
