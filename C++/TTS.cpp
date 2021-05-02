#include <iostream>
#include <cstring>

using namespace std;
const int cols = 16, rows = 15;

 char words[rows][cols] = {"tgbwwinterwsesn",
                                "aaunttmmhfoodnb",
                                "jlwcqldzmpmvdmr",
                                "asagmquwvvbsohi",
                                "bwplotanadtpgnc",
                                "rewngodjcpnatnk",
                                "eeotwosbqharrsa",
                                "azcgeswewnaknpb",
                                "dinnerqodlwdcar",
                                "onopkwmparktzcc",
                                "qbfrogmamwpweey",
                                "lqzqnnmrzjjsclg",
                                "mosgzczetdbooto",
                                "pdcrzmsngrdnrpz",
                                "ohnkzwaterjgtra"};

char *getWordVertical(int n);
char *reverse(char *word);
bool searchVertical(char *word);
bool searchHorizontal(char *word);

int main()
{
    char word[16];
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
    	cout << "asd : ";
        cin.getline(word,16);
        if (searchVertical(word) || searchHorizontal(word))
            cout << "Ada\n";
        else 
            cout << "Tidak Ada\n";
    }
    return 0;
}

char *getWordVertical(int n) {
	
}

char *reverse(char *word) {
	int n = strlen(word);
	int p = n/2;
	for(int i=0; i<p; i++, n--) {
		swap(word[i], word[n-1]);
	}
	return word;
}

bool searchVertical(char *word) {
	bool check = false;
	int found = 0;
	int n = strlen(word);
	
	for(int x=0; x<rows; x++) {
		for(int y=0; y<cols; y++) {
			if(word[found] == words[x][y]) {
				for(int z=x; word[found] == words[z][y]; z++) {
					found++;
					if(found == n) {
						check = true;
						break;
					}
				}
			}
			if(word[found+1] != words[x][y+1]){
				found = 0;
			}
		}
		if(check) break;
	}
	
	if(check == false) {
		for(int x=0; x<rows; x++) {
			for(int y=0; y<cols; y++) {
				if(word[found] == words[x][y]) {
					for(int z=x; word[found] == words[z][y]; z--) {
						found++;
						if(found == n) {
							check = true;
							break;
						}
					}
				}
				if(word[found+1] != words[x][y+1]){
					found = 0;
				}
			}
			if(check) break;
		}
	}
	
	return check;
}

bool searchHorizontal(char *word) {
	bool check = false;
	int found = 0;
	int n = strlen(word);
	
	for(int x=0; x<rows; x++) {
		for(int y=0; y<cols; y++) {
			if(word[found] == words[x][y]) {
				for(int z=y; word[found] == words[x][z]; z++) {
					found++;
					if(found == n) {
						check = true;
						break;
					}
				}
			}
			if(word[found+1] != words[x][y+1]){
				found = 0;
			}
		}
		if(check) break;
	}
	
	if(check == false) {
		reverse(word);
		
		for(int x=0; x<rows; x++) {
			for(int y=0; y<cols; y++) {
				if(word[found] == words[x][y]) {
					for(int z=y; word[found] == words[x][z]; z++) {
						found++;
						if(found == n) {
							check = true;
							break;
						}
					}
				}
				if(word[found+1] != words[x][y+1]){
					found = 0;
				}
			}
			if(check) break;
		}
	}
	
	return check;
}

