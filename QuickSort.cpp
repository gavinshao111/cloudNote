qsort(char *s, int first, int last) {
    if (first < last) {
        int i = first, j = last;
        char x = s[i];
        while (i < j) {
            while (i < j && s[j] >= x) //��j��ǰ�ұ�xС��ֵ
                j--;
            if (i < j) {
                s[i] = s[j];
                i++;
            }
            while (i < j && s[i] < x) //��i�����ұ�x���ֵ
                i++;
            if (i < j) {
                s[j] = s[i];
                j--;
            }
        }
        s[i] = x;
        qsort(s, first, i - 1);
        qsort(s, i + 1, last);
    }
}

int main(void) {
    char p[10] = {...}
    qsort(s, 0, 9);
}
