/* Wan Aufa Azis - 18221001 */
/* 09 September 2022 */

/* PROGRAM DERET KARAKTER */
/* Menerima sebuah karakter dan integer, lalu menuliskan karakter sebanyak integer */

int main()
{
    /* KAMUS */
    char C;
    int n;
    int i;

    /* ALGORITMA */
    scanf("%c",&C);
    scanf("%d",&n);
    i=1;

    for(i;i<=n;i++)
    {
        printf("%c",C);
    }
    return 0;
}
