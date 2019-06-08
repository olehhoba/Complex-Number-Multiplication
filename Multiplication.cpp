#include <iostream>
#include <vector> 
#include <string>
using namespace std;
void multiplication(int &a,int n)
{
    for(int i=1; i<=n; i++)
    {
        a*=10;
    }
}
void array_to_int(int & a_int,std::vector<int> a_v)
{
    int a=0;
    for(int i=0; i<a_v.size(); i++)
    {
        a=a_v[i];
        multiplication(a,a_v.size()-i-1);
        a_int+=a;
    }
}
void separate_re_im(std::string a,int & re_a_int,int & im_a_int)
{
    std::vector<int>re_a_v;
    std::vector<int>im_a_v;
    int c=0;
    int d=0;
    if(a[0]=='-')
    {
        d=-1;
    }
    for(int i=0; i<a.size(); i++)
    {
        if((int)a[i]>=48 && (int)a[i]<=57 && c==0)
        {
            re_a_v.push_back(((int)(a[i]))-'0');
        }
        else if((int)a[i]>=48 && (int)a[i]<=57)
        {
            im_a_v.push_back(((int)(a[i]))-'0');   
        }
        else if(((int)a[i])==43 && i>0)
        {
            c=1;
        }
        else if(((int)a[i])==45 && i>0)
        {
            c=-1;
        }
    }
    array_to_int(re_a_int,re_a_v);
    array_to_int(im_a_int,im_a_v);
    if(c==-1)
    {
        im_a_int*=-1;
    }
    if(d==-1)
    {
        re_a_int*=-1;
    }
}

int main()
{   
    std::string a="78+-76i",b="-86+72i";
    int re_a_int=0,re_b_int=0,im_a_int=0,im_b_int=0;
    separate_re_im(a,re_a_int,im_a_int);
    separate_re_im(b,re_b_int,im_b_int);
    std::string res_s;;
    int res_i;
    res_i=re_a_int*re_b_int+((im_a_int*im_b_int)*-1);   
    res_s+=std::to_string(res_i);
    res_s+='+';
    res_i=re_a_int*im_b_int+re_b_int*im_a_int;
    res_s+=std::to_string(res_i);
    res_s+='i';
    std::cout<<res_s<<std::endl;
    return 0;

}
  
