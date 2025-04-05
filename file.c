#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char ch, str1[1000],str2[1000],str3[1000];
    gets(str1);
    int count = 0;
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1 = fopen("input.txt","w");
    fprintf(fp1,"%s",str1);
    fclose(fp1);


    //total number of words
    fp2 = fopen("input.txt","r");
    while(fscanf(fp2,"%s",str2) != EOF)
    {
        count++;
        printf("%s ",str2);
    }
    fclose(fp2);
    printf("\nNumber of words = %d\n",count);
    //separate vowel and consnant
    fp3 = fopen("input.txt","r");
    fp4 = fopen("vowelstart.txt","w");
    fp2 = fopen("consonantstart.txt","w");
    while(fscanf(fp3,"%s",str2) != EOF)
    {
        if(str2[0] == 'A' || str2[0] == 'a' || str2[0] == 'E' || str2[0] == 'e' || str2[0] == 'I' || str2[0] == 'i' || str2[0] == 'O' || str2[0] == 'o' || str2[0] == 'U' || str2[0] == 'u')
        {
            fputs(str2,fp4);
            fputc(' ',fp4);
        }
        else
        {
            fputs(str2,fp2);
            fputc(' ',fp2);
        }
    }
    fclose(fp3);
    fclose(fp4);
    fclose(fp2);
    //perfect integer
    count = 0;
    fp1 = fopen("input.txt","r");
    fp2 = fopen("integers.txt","w");
    while(fscanf(fp1,"%s",str2) != EOF)
    {
        int len = strlen(str2);
        for(int i = 0; i < len; i++)
        {
            ch = str2[i];
            if(ch == '0' || ch == '1' || ch == '2' ||ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
            {
                count++;
            }
        }
        if(count == len)
        {
            fputs(str2,fp2);
            fputc(' ',fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    //valid floting
     count = 0;
    fp1 = fopen("input.txt","r");
    fp2 = fopen("floats.txt","w");
    while(fscanf(fp1,"%s",str2) != EOF)
    {
        int len = strlen(str2);
        for(int i = 0; i < len; i++)
        {
            ch = str2[i];
            if(ch== '.' == '0' || ch == '1' || ch == '2' ||ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
            {
                count++;
            }
        }
        if(count == len)
        {
            count=0;
            for (int i=0;i<len;i++)
            {
                if (str2[i]=='.'){count++;break;}
            }
            if (count==1)
            {
                fputs(str2,fp2);
                fputc(' ',fp2);
            }

        }
    }
    fclose(fp1);
    fclose(fp2);
    //identifier cheack
    fp1 = fopen("input.txt","r");
    fp2 = fopen("identifiers.txt","w");
    while(fscanf(fp1,"%s",str2) != EOF)
    {
        int len = strlen(str2);
        if (str2[0]=='_'||(str2[0]>=97||str2[0]<=122)||(str2[0]>=63||str2[0]<=90))
        {
            for (int i=0;i<len;i++)
            ch = str2[i];
            if(ch=='_'||(ch>=97||ch<=122)||(ch>=63||ch<=90)||ch == '0' || ch == '1' || ch == '2' ||ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
            {
                count++;
            }
        }
        if(count == len)
        {

                fputs(str2,fp2);
                fputc(' ',fp2);


        }

}
     fclose(fp1);
    fclose(fp2);

    return 0;
}


