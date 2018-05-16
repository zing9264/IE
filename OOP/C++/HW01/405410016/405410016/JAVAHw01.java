import java.io.*;
import java.util.*;
public class JAVAHw01{
    public static void main(String[] args){ //throws IOException 
		char[] pat;
		char[] npat=new char[500];
		int n=-1,i,j;
		String text;
		Scanner input;
		System.out.println("input 0 to quit "); 
		
		outerloop:
		while(true){
			Arrays.fill(npat,'\0');  //reset
			j=0;
			System.out.print("please input a sentence:");
			input = new Scanner(System.in);		
			text=input.nextLine();
            n=text.length();	
			if(n==0){
				continue;
			}
			text=text.toUpperCase();
            pat=text.toCharArray();
            if(pat[0]=='0' && n==1){ //exit
				System.exit(0);
			}

            for(i=0;i<n;i++){
				if( (pat[i]>='A' && pat[i]<='Z') || (pat[i]>='0' && pat[i]<='9') ){
					npat[j]=pat[i];
					j++;
				}
			}//for
			npat[j]='\0';
			String rmspace=new String(npat);
			rmspace=rmspace.trim();
			n=rmspace.length();
			
			for(i=0;i<n/2;i++){
				if(npat[i]!=npat[n-1-i]){
				System.out.println("It Is Not a Palindrome!"); 
				continue outerloop;
				}				
			}
			System.out.println("It Is a Palindrome!"); 			
		}//while
	
    }//main
}//class


