#include <stdio.h>
#include <string.h>

char chem[114][2]={"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
   "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr"};

int alpha[26][27]={0,};

char a[50001];
int chk[50001];

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);
    //freopen("input.txt","r",stdin);
    for(int i=0;i<114;i++){  // 주기율표 모든 원소 소문자화
            chem[i][0]+=32;
            if(chem[i][1]=='\0'){ // alpha 배열에 주기율표 값 int화 하여 저장
                alpha[chem[i][0]-'a'][26]=1;
            }
            else{
                alpha[chem[i][0]-'a'][chem[i][1]-'a']=1;
            }
    }

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        memset(chk,0,sizeof(chk));

        scanf("%s",a);
        int len=strlen(a);

        for(int dp=0;dp<len;dp++){
            if(dp==0){
                if(alpha[a[dp]-'a'][26]==1){
                    chk[dp]=1;
                }
            }
            if(dp==1){
                if(alpha[a[dp-1]-'a'][a[dp]-'a']==1){
                    chk[dp]=1;
                }
                if(chk[dp-1]==1 && alpha[a[dp]-'a'][26]==1){
                    chk[dp]=1;
                }
            }
            else{
                if(chk[dp-1]==1 && alpha[a[dp]-'a'][26]==1) chk[dp]=1;
                else if(dp>=2 && chk[dp-2]==1 && alpha[a[dp-1]-'a'][a[dp]-'a']==1){
                     chk[dp]=1;
                }
            }
        }
        
		printf("Case #%d\n", test_case+1);
        chk[len-1]==1?printf("YES\n"):printf("NO\n");
        
	}

	return 0;
}