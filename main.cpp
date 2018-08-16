#include <iostream>

using namespace std;



void pisos(int k){
		for (int i = 0; i < k; ++i){
			cout<<"pisos"<<endl;
	}
}

int numx(int k){
	return k*k;
}


int main(){
    int k = 0;
    //privet mama papa babushka ii kot
    cin>>k;
    for (int i = 0; i <= k ; ++i)
    {
    	if (i+1>k){
    		pisos(1);
    	}else{
    	cout << numx(i+1)<<endl;
    	}

    }
    return 0;
}
