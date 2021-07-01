#include<bits/stdc++.h>
using namespace std;


//to store three category of products
struct Products{
    string compnay_name;
    string device_name;
    int price;
};

//to sort on the basis of price

bool compare(const Products &a,const Products &b){
    return a.price<b.price;
}

int main(){
    string str;
    getline(cin,str);
    
  
    vector<string> v;
 
    stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
    vector<Products>product;
    bool flag=true;
    int count=0;
    Products id;
    for (size_t i = 0; i < v.size(); ){

        if(count==0){
            id.compnay_name=v[i];
            count+=1;
            i++;


        }else if(count==1){
            string str1=v[i];
            string temp=v[i];
            while(temp[temp.length()-1]!='\''){
                  
                  i++;
                  str1+=",";
                  str1+=temp;
                  temp=v[i];
            }
            str1+=",";
            str1+=temp;
            id.device_name=str1;
            count++;
            i++;

        }
        else if(count==2){
            id.price=stoi(v[i]);
            product.push_back(id);
            count=0;
            i++;

        }
        

    }
    sort(product.begin(),product.end(),compare);
    cout<<"\n\n";
    for(int i=0;i<product.size();i++){
        cout<<product[i].compnay_name<<","<<product[i].device_name<<","<<product[i].price<<endl;
        cout<<endl;
        
        
    }
        

    return 0;
}