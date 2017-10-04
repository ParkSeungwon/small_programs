 #include<iostream>
    #include<map>
    using namespace std;

    class nHr
    {
    public:
        nHr(int n, int r) {
            this->n = n;
            this->r = r;
            ar = new int[r];
        }
        int* ar;
        int n, r;
        bool next() {
            ar[r-1]++;
	        int i = r-1;
         	while(ar[i] == n+1) {
          		if(--i == -1) return false;
         		ar[i]++;
         	}
            while(i < r-1) ar[i+1] = ar[i++];
	        return true;
        }
		int operator[](int n) {
			return ar[n];
		}
    };

    int main(int c, char** v)
    {
    	if(c < 3) return 0;
	    int x = atoi(v[1]);
    	int y = atoi(v[2]);
	    nHr nhr(y, x-y);
    	map<int, int> m;
	    while(nhr.next()) {
    		for(int i=1; i<=y; i++) m[i]++;
		    for(int i=0; i<x-y; i++) m[nhr[i]]++;
	    	for(auto& a : m) cout << a.second << '+';
    		cout << endl;
		    m.clear();
	    }
    }
