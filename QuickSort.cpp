qsort(char *s, int first, int last){
    if(first < last){
	int i = first, j = last;
	char x = s[i];
	while(i<j){
	    while(i<j)	//从j往前找比x小的值
		if(s[j]<x)
		    break;
	    if(i < j){
		s[i] = s[j];
		i++;
	    }
	    while(i<j)	//从i往后找比x大的值
		if(s[i]>x)
		    break;
	    if(i < j){
		s[j] = s[i];
		j--;
	    }
	}
	s[i] = x;
	qsort(s,first,i-1);
	qsort(s,i+1,last);
	}
    }
    
}

int main(void){
    char p[10]={...}
    qsort(s,0,9);
}
