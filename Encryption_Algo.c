#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char key[5];
int num(char ch)
{
    if(ch<='Z' && ch>='A')
        return (int)ch-65;
    else
        return (int)ch-97;
}
char de_num_capital(int key_num)
{
	int temp= key_num % 26;
	temp=temp+65;
	return (char)temp;
}
char de_num_small(int key_num)
{
	int temp= key_num % 26;
	temp=temp+97;
	return (char)temp;
}
char encrypt_algo(char ch)
{
    int key_num;
    static int count=0;
    if((ch<='Z' && ch>='A') || ( ch<='z' && ch>='a'))
    	{
    		key_num= num(ch)+num(key[count % 4]);
    		count++;
    		if(ch<='Z' && ch>='A')
                ch=de_num_capital(key_num);
            else
                ch=de_num_small(key_num);
    	}
    	return ch;

}
char decrypt_algo(char ch,int numm)
{
    int key_num;
    static int count=0;
    if(numm==-1)
    {
        count=0;
        return '\0';
    }
        if((ch<='Z' && ch>='A') || ( ch<='z' && ch>='a'))
    	{
    	    if(num(ch)-num(key[count % 4])>=0)
    		{
    		    key_num= num(ch)-num(key[count % 4]);
                count++;
                if(ch<='Z' && ch>='A')
                    ch=de_num_capital(key_num);
                else
                    ch=de_num_small(key_num);
    		}
    		else
            {
                key_num=(26+num(ch))-num(key[count % 4]);
                count++;
                if(ch<='Z' && ch>='A')
                    ch=de_num_capital(key_num);
                else
                    ch=de_num_small(key_num);
            }
    	}
    	return ch;
}

char caesarCipher_encrypt(char ch, int shift)
{
    
    int i, key;
    
    // printf("Enter a message to encrypt: ");
    // gets(message);
    // printf("Enter shift: ");
    // scanf("%d", &key);
    if(ch!='\0')
    {
        
        if(ch >= 'a' && ch <= 'z'){
        ch = ch + shift;
        if(ch > 'z'){
        ch = ch - 'z' + 'a' - 1;
    }
    // message[i] = ch;
    }
    else if(ch >= 'A' && ch <= 'Z'){
    ch = ch + shift;
    if(ch > 'Z'){
    ch = ch - 'Z' + 'A' - 1;
    }
    // message[i] = ch;
    }
    }
    return ch;
}
void encrypt()
{
    system("cls");
    FILE* f1;
    int count=0,count_num=0;
    printf("\n\nEnter the 4 letter Key: ");
    fflush(stdin);
    int i;
    for(i=0;i<4;i++)
    {
        scanf("%c",&key[i]);
    }
    key[4]='\0';
    f1=fopen("Encrypted.txt","w");
    fflush(stdin);
    char ch;
    for(i=0;i<4;i++)
    {
        fprintf(f1,"%c",encrypt_algo(key[i]));
    }
    fprintf(f1," ");
    printf("Enter the contents:\n");
    while( (ch=getchar()) != EOF)
    {
        ch=encrypt_algo(ch);
    	putc(ch,f1);
    }
    fclose(f1);
    printf("\n---------------------THE FILE HAS BEEN CREATED--------------------------");

}
void encrypt_old()
{
    system("cls");
    FILE* f1;
    FILE* f2;
    FILE* f3;
    printf("Select the File");
    system("File_Chooser.bat");
    f3=fopen("testlog.txt","r");
    char File[100];
    int i,count=0,count_num=0;
    char ch;
    fscanf(f3,"%[^\n]",File);
    fflush(stdin);
    system("cls");
    printf("Enter the 4 letter Key: ");
    for(i=0;i<4;i++)
    {
        scanf("%c",&key[i]);
    }
    key[4]='\0';
    f1=fopen(File,"r");
    f2=fopen("Enc.txt","w");
    fflush(stdin);
    count=0;
    for(i=0;i<4;i++)
    {
        fprintf(f2,"%c",encrypt_algo(key[i]));
    }
    fprintf(f2," ");
    while( (ch=getc(f1)) != EOF)
    {
    	ch=encrypt_algo(ch);
    	putc(ch,f2);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    remove(File);
    remove("testlog.txt");
    rename("Enc.txt",File);
    printf("\n---------------------THE FILE HAS BEEN ENCRYPTED--------------------------");

}

char hash(int index)
{
    
    return (char)(index);
}

void caesar_old()
{
    system("cls");
    FILE* f1;
    FILE* f2;
    FILE* f3;
    printf("Select the File");
    system("File_Chooser.bat");
    f3=fopen("testlog.txt","r");
    char File[100];
    int i,count=0,count_num=0;
    char ch;
    int shift;
    fscanf(f3,"%[^\n]",File);
    fflush(stdin);
    system("cls");
    printf("Enter new the shift: ");
    scanf("%d",&shift);
    
    f1=fopen(File,"r");
    f2=fopen("Enc.txt","w");
    // fputs("This is c programming.", f2);
    putc('2',f2);

    fflush(stdin);
    count=0;

   



    
    
    fprintf(f2," ");
    // if(f2){
    //     int i =2;
    //     fprintf(f2,"%d\n",i);
    // }
    int a;
    while( (ch=getc(f1)) != EOF)
    {
        printf("inside while");
    	ch=caesarCipher_encrypt(ch, shift);
    	putc(ch,f2);
        
        // a = hash(2);
        // putc(a,f2);
        
    }
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
    remove(File);
    remove("testlog.txt");
    rename("Enc.txt",File);
    printf("\n---------------------THE FILE HAS BEEN ENCRYPTED--------------------------");

}

void decrypt()
{
    system("cls");
    char File[100];
    FILE* f3;
    printf("Select the File");
    system("File_Chooser.bat");
    f3=fopen("testlog.txt","r");
    fscanf(f3,"%[^\n]",File);
    int i,count=0,count_num=0;
    char ch;
    fflush(stdin);
    int flag=0,flag1=0;
    system("cls");
    FILE* f1;
    FILE* f2;
    f1=fopen(File,"r");
    re_enter:
    flag1=0;
    printf("Enter the 4 letter Key: ");
    i=0;
    for(i=0;i<4;i++)
    {
        scanf("%c",&key[i]);
    }
    key[4]='\0';
    fflush(stdin);

    for(i=0;i<4;i++)
    {
        ch=getc(f1);
        if(key[i]!=decrypt_algo(ch,0))
        {
            flag++;
            rewind(f1);
            flag1=-1;
            break;
        }
    }


    if(flag!=0 && flag1==-1)
    {
        if(flag==3)
        {
            fclose(f1);
            fclose(f3);
            remove(File);
            remove("testlog.txt");
            printf("----------------------------The File Has Been Deleted---------------------------");
            return;
        }
        else
        {
            printf("Invalid Key Only %d try remaining\n",3-flag);
            char m = decrypt_algo('a',-1);
            goto re_enter;
        }
    }
    ch=getc(f1);
    f2=fopen("Decrypted.txt","w");
    while((ch=getc(f1)) != EOF)
    {
        ch=decrypt_algo(ch,0);
    	putc(ch,f2);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    remove(File);
    remove("testlog.txt");
    rename("Decrypted.txt",File);
    printf("\n---------------------THE FILE HAS BEEN DECRYPTED--------------------------");
}

int main()
{
    printf("1. Create an new encrypted File\n");
    printf("2. Encrypt a file\n");
    printf("3. Decrypt an encrypted File\n");
    int choice;
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        encrypt();
        getch();
        return 0;
    case 2:
        int choice1;
        printf("Pick your encryption method: \n1. monoalphabetic cipher \n2. Caesar Cipher\n");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 1:
                encrypt_old();
                printf("Case1");
                getch();
                return 0;
            case 2:
                caesar_old();
                printf("Case2");
                getch();
                return 0;
        }
        

        
    case 3:
        decrypt();
        getch();
        return 0;
   

    }
}
