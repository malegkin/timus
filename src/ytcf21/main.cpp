#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>

struct node{
    int i1;
    int i2;
    bool is_branch =false;
};
int main()
{    
    std::string p1, p2, pr;
    
    std::getline(std::cin, p1);
    std::getline(std::cin, p2);
    std::getline(std::cin, pr);
    
    int pa1[256], pa2[256], par[256];
    memset(pa1, 0, sizeof(pa1)); 
    memset(pa2, 0, sizeof(pa2));
    memset(par, 0, sizeof(par));

    for(char& c : p1) {
        pa1[c]++;
    }
    for(char& c : p2) {
        pa2[c]++;
    }
    for(char& c : pr) {
        par[c]++;
    }

    for (int i = 0 ; i < 256; i++){
        //std::cout << i << " " << pa1[i] << " " << pa2[i] << " " << par[i] << std::endl;
        if (pa1[i] + pa2[i] != par[i]){
            std::cout  << "NO";
            return 0;
        }
    } 
    
    
    
    
    //std::cout << "main"<< std::endl;
    std::array<node, 10000> l;

    int i1=0, i2=0, ir=0;
    for(; ir < pr.size(); ir++){
        //std::cout << i1 << " " << i2 << " " << ir << std::endl;
                //std::cout << p1[i1] << " " << p2[i2] << " " << pr[ir] << std::endl;
        l[ir].i1 = i1;
        l[ir].i2 = i2;
   
        if (pr[ir] == p1[i1] && pr[ir] == p2[i2]){
            l[ir].is_branch = true;
            l[ir].i1++;
            i1++;
            //std::cout << "branch" << std::endl;

        } else if (pr[ir] == p1[i1]){
            l[ir].i1++;
            i1++;
            //std::cout << "1" << std::endl;

        } else if (pr[ir] == p2[i2]){
            l[ir].i2++ ;
            i2++;
            //std::cout << "2" << std::endl;
        } else {
            
            int j = ir;
            for(; !l[j].is_branch; j--){
                if (j == -1){
                    std::cout << "NO";
                    return 0;                
                }
            }
                   ir = j;
                    l[ir].is_branch = false;
                    i1 = --l[ir].i1;
                    i2 = ++l[ir].i2;
                    
                    //std::cout << "bb" << std::endl;

            }
        }
    
    
    //std::cout << i1 << " " << i2 << " " << pr.size() << std::endl;
    
    if (i1+i2 == pr.size() && p1.size() == i1 && p2.size() == i2)
        std::cout << "YES";
    else 
        std::cout << "NO";
    return 0;                
}