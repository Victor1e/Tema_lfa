//1. Prima problema:


#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void check(char cuvant[], int stare_actuala,int stari_fin[],int lung,int mat[][30])
{
    for(int i=0; cuvant[i]!='\0';i++)
    {
        stare_actuala=mat[stare_actuala][cuvant[i]-'a'];
        if(stare_actuala==0){
            fout<<"NU"<<'\n';
            break;
        }
    }
    int ok=0;
    if(stare_actuala!=0)
    {
        for(int i=1;i<=lung;i++)
        {
            if(stare_actuala==stari_fin[i]){
                fout<<"DA\n";
                ok=1;
            }
        }
        if(ok==0)
        fout<<"NU\n";
    }


}
int main()
{
    int n,x,y,m,nr1,nr2,s,nrf;
    char l;
    fin>>n;
    int v[n+1];
    for(int i=1;i<=n;i++)
        fin>>v[i];
    fin>>m;
    int mat[n+1][30]={0};
    for(int i=1;i<=m;i++){
        fin>>x>>y>>l;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==x)nr1=i;
            if(v[i]==y)nr2=i;
        }
        mat[nr1][l-'a']=nr2;
    }
    int stare_init;
    fin>>s;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==s)
            stare_init=i;
    }
    fin>>nrf;
    int stari_fin[nrf+1];
    int cnt=1;
    int stare;
    for(int i=1;i<=nrf;i++)
    {
        fin>>stare;
        for(int j=1;j<=n;j++)
        {
            if(v[j]==stare)
                stari_fin[cnt++]=j;
        }
    }
    cnt--;
    int nrCuv;
    char cuvant[256];
    fin>>nrCuv;
    for(int i=1;i<=nrCuv;i++)
    {
        fin>>cuvant;
        check(cuvant,stare_init,stari_fin,cnt,mat);
    }
    return 0;
}
