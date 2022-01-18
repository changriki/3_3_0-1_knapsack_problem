#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
using namespace std;

int max(int a, int b) {return (a > b) ? a : b;}

const int N = 10000, W = 10000;
int c[N + 1][W + 1];
bool p[N][W + 1];
 
void knapSack(int w, int weight[], int cost[], int n) { 
	int p[n+1][w+1];
    for (int i=0; i<n; i++){
        for (int j = 0; j<=w; j++){
            if (j-weight[i] < 0){
                c[i+1][j] = c[i][j];
                p[i+1][j] = p[i][j];
            }
            else{
                c[i+1][j] = max(c[i][j], c[i][j-weight[i]] + cost[i]);
                
                if((c[i][j-weight[i]] + cost[i]) > c[i][j]) p[i][j] = true;
                else p[i][j] = false;
            }
        }
    }

    for (int i=n-1, j=w; i>=0; i--) {
        if (p[i][j]) {
            cout << i << " ";
            j -= weight[i];
        }
    }

    cout << endl << c[n][w] << endl;
}

int main() {
	int lines = 0;
	int BackpackSize;
	int number[W];
	int weight[W], Weight[W]={0};
	int value[W], Value[W]={0};

	// cin >> BackpackSize;
	// for(int j=0; j<=W; j++) {
 //        cin >> number[j] >> weight[j] >> value[j];
 //        lines = j;

 //        if(number[j]==-1 && weight[j]==-1 && value[j]==-1) {
 //        	break;
 //        }
 //    }

//############# read from file, begin
    string filename("3_3_input.txt");
    int Number;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    int i = -1;
    while (input_file >> Number) {
        lines = i/3;
        int ii = i%3;
        cout << "(i = " << i << ")";
        i++; // i++ required here!!!!!!!!!
        if(i==0) {
            BackpackSize = Number;
            cout << ", BackpackSize = " << BackpackSize << endl;
            continue;
        }
        else if(ii==0) {
            number[lines] = Number;
            cout << ", number = " << number[lines];
        }
        else if(ii==1) {
            weight[lines] = Number;
            cout << ", weight = " << weight[lines];
        }
        else if(ii==2) {
            value[lines] = Number;
            cout << ", value = " << value[lines] << endl;
        }
        else if(number[lines]==-1 && weight[lines]==-1 && value[lines]==-1) break;
    }
    cout << "lines = " << lines << endl;

    input_file.close();
//############# read from file, end

    for(int k=0; k<lines; k++) {
        Weight[number[k]] = weight[k];
        cout << number[k] << " weight = " << weight[k] << endl; 
        Value[number[k]] = value[k];
        cout << number[k] << " value = " << value[k] << endl; 

    }

    knapSack(BackpackSize, Weight, Value, lines);

	return 0;
}
