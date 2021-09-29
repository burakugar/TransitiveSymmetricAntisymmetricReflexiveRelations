// BURAK UGAR 200104004100
// Firstly, apologise for bad connection for the second homework,There are always problems with connection in that process.
// I did my last settings and then upload but my browser is failed to upload so that i emailed you about the
// late submission and sent this code's ancestor with my pdf file zipped each other. It was 2 minutes later then the submission time 23.57
// I will promise to be more careful about next submissions and fix my internet connection before submit it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for string executions
#define MAX_TAKE 10 // max number of element can be assigned to "array" in main
void clear_newline(char line[]){/*Clear newline character in string*/

	int i;
	for(i=0; (line[i]!=0 && line[i]!='\n'); i++);
	line[i]=0;}

void printPairs(char b[][3],int n){ // this function prints the pairs to output.txt which are given
		FILE *fp1;
		int i=0;
		fp1= fopen("output.txt","a+");
		if(fp1 == NULL){
			printf("Error opening the file output.txt"); // File error checking
		}
		while(i<n){
			fprintf(fp1,"(%c,%c) ", b[i][0], b[i][2]); // we are printing the matrix's first third element since it contains comma in the middle such as 2,1
			i++;
			}
			fprintf(fp1,"\n"); // new line for printing the below pair properly
			fclose(fp1);
	}

void reflexive(char b[][3],char *array,int n){ //function that find whether a set is reflexive or not
	int i,cnt=0;
	int k=0;   // variables
	int commanumber = 0;
	FILE *fp;
	fp= fopen("output.txt","a+"); //Opening the output file we choose a+ since we want to modify previous file because we call our functions relatively as in 	
		if(fp == NULL){
			printf("Error opening the file output.txt"); // File error checking
		}
		
		for(i=0; array[i]; i++) {
    			if(array[i] == ',') { // We are counting the number of the commas in input array
        	commanumber ++;
    	}
	}
		commanumber+=1; // element number have to be greater 1 than comma number, so we update the value of comma number by adding 1
	 for(i=0;i<n;i++){
  		if(b[i][0]==b[i][2])
  			cnt++;  // we are looking for the matrix which has pairs in input.txt and counting the pairs which contain equal first and second elements
  					// such as (1,1) (2,2) (3,3)
 	}
 		if(cnt==(strlen(array)+1)/2){ //Formula has been produced from number of elements in input array 
		 								//if this is equal to number of pairs which are in the array b, then the relation is reflexive
 			fprintf(fp,"Reflexive since all reflexive elements in the set are present\n");
 		}
			else
			fprintf(fp,"Not reflexive since number of reflexive element have to be %d but it is %d \n", commanumber, cnt); //If the numbers are not equal then set is not reflexive
			fclose(fp); //Closing the file
			}

void transitive(char b[][3],char *array,int n){  //function that find whether a set is reflexive or not
	FILE *fp;
	fp = fopen("output.txt","a+"); // opening the file to write
	if(fp == NULL){
			printf("Error opening the file output.txt"); // File error checking
		}
	int l= 0;
	int i;   
	int j=0;
	int check = 0;
		for(l=0;l<n;l++){

			if(b[l][0] == b[l][2]){  // we are checking the matrix's elements if the first and second element are equal 
				continue; // if they're equal we have to pass this pair because transitivity there is no extra effort to check transitivity so continue
		}
		for(i=0;i<n;i++){
			if(l == i){
				continue;	// to check transivity we have to have a double for loop so that we have to check this loop's variable's to not equal each other which means
							// they stand for same pair, we have to check other pairs not the same ones
			}
			if(b[i][0] == b[i][2]){	// same is valid for other for loop: we are checking the matrix's elements if the first and second element are equal.
									//if they're equal we have to pass this pair because transitivity there is no extra effort to check transitivity so continue as well
				continue; 
			}
			if(b[l][2] == b[i][0]){
				while(j<n){
					if(j==l && j == i){ 
						continue;		// we have to have a temporary third loop which provides us to control both first loop and second loop's element 
					}					// for example, if there exist 1,2(l) and 2,3(i) we have to check if there exist any 1,3(j) in the matrix.
										// for the third loop,it should hold same controls as well which is there is no need to check first and second elements.
					if(b[j][0] == b[l][0] && b[j][2] == b[i][2]){ // actual transivity control which is for example if there exist any pair 1,3 if there are pairs
																  // 1,2 and 2,3.
						check = 1;						// if there is, hold check to 1 and break.					
						break;
					}
					else{
						check =-1;						// if there is not, hold check to -1 and break
					}
					j++;           						// increment j for to control other pairs
				}
			}
			if(check == -1){
				break;      // This control is for the last element, if it is not transitive then break
			}
		}
		if(check == -1){
			fprintf(fp,"Not transitive, (%c,%c) and (%c,%c) is found but (%c,%c) can not be found.\n",b[l][0],b[l][2],b[i][0],b[i][2],b[l][0],b[i][2]);
			break;
			// if the pair is not found then print that pair
		}
	}
		if(check == 0){
		fprintf(fp,"Yes, (%c,%c) is found and all the other values are transitive.\n",b[0][0],b[0][0]);	// If the set is consisted by pairs which have element that first 
																										// is equal to second one, then control variable will never change and then
																										// we'll understand that all pairs consist of with that type for instance set (1,1),(2,2) 
		for(i=1;i<n;i++){
		fprintf(fp,"Yes, (%c,%c) is found and all the other values are transitive.\n",b[i][0],b[i][0]);	// for some printing issues, i have to print first pair than others then it was solved 

		}
		}
		if(check == 1){
		fprintf(fp,"Yes, there is no pair which blocks transivity. \n"); // If we found the pair in the loop's inside then it means that control statement was changed because there are pairs
		//which's first and secont elements are not equal to each other. For that situation it means there is no pair which blocks transivity.
		
	}
	fclose(fp);
}
void symmetric(char b[][3],int n){ // Function that finds symmetric relations
 	FILE *fp;
	fp= fopen("output.txt","a+"); 
	
	if(fp == NULL){
		printf("Error opening the file output.txt"); // File error checking
		}
	 int i,j,k;
 	 int flag;
	 for(i=0;i<n;i++){     // initially,we need 2 for loops to handle finding pairs that are symmetric to each other
	 	for(k=0;k<n;k++){
 		if(b[i][0]==b[i][2]){
 			continue;		// as is mentioned above,we have no need to check pairs which are equal in terms of first and second element, so pass them and continue to take pairs
		 }
	}
		flag=0;				// flag is 0 initally, if there are symmetric pairs then it will be 1
		j=0;
 		while(j<n){
			if(b[i][0]==b[j][2]&&b[i][2]==b[j][0]){
				 flag = 1;
 			}
 			j++;
	 }
 		if(flag==0){
 			fprintf(fp,"Not symmetric since (%c,%c) exists but (%c,%c) is not found \n",b[i][0], b[i][2],b[i][2],b[i][0]); // if the flag is 0 ,there is no pair which is symmetric
 			break;
		 }
}
 	if(flag==1){
 		fprintf(fp,"Symmetric. There is no pair which blocks the symmetry. \n"); // if flag 1, there exist
	 }
	fclose(fp);
 }

void antisymmetric(char b[][3],char array[10],int n){ // Function that finds antisymmetric relations
	FILE *fp;
	fp = fopen("output.txt","a+");
	if(fp == NULL){
		printf("Error opening the file output.txt");
			} // File error checking
	int control = 0,i,k,index;
	int count1 = 0,count2 = 0;
	while(count1<n){					
		if(b[count1][0] == b[count1][2]){ // we are counting the number of the pairs have first and secont elements are equal and store them in count2
			count2++;
		}
		count1++;
	}
	for(k=0;k<n;k++){
		if(count2 == count1){
			fprintf(fp,"Antisymmetric since all elements are same with each other.\n"); // If count1 and count2 are equal that means we increment count2 as much count1
			control = 3; // control is 3
			break;
		}
		control = 0; // to check other pairs make control 0 again
		if(b[k][0] == b[k][2]){
			continue;				// dont check the same pairs again continue when confront
		}					
		i=0;
		for(i=0;i<n;i++){
			if(k == i){			// now it's time to check other pairs. if there are symmetric values that means there is no antisymmetry so we hate to look at 
								// them by take a variable i and put it into a loop to check other pairs until the number n which is the number of pairs
				continue;				
			}
			if(b[k][0] == b[i][2] && b[k][2] == b[i][0]){ 						
				control = 1;   // if there is a case such as 1,2 and 2,1 then relation turns not antisymmetric
				fprintf(fp,"Not antisymmetric since (%c,%c) exist when (%c,%c) exist as well.\n",b[k][0],b[k][2],b[k][2],b[k][0]);
			}		
		}

		if(control == 1){
			break; // one pair is enough to make relation not antisymmetric,there is no need to check others in loop
		}
	}
	if(control == 0){
		fprintf(fp,"Antisymmetric since all elements are present\n"); // if control was never been changed that means all elements holds the antisymmetry
	}
	fclose(fp);
}

int main(){
		FILE *fp1;
		int i,j,k,n;
		char array[10]; // This array holds values in the input file such as a,b,c,d,e or 1,2,3,4
		char x;
		
		fp1= fopen("input.txt","r");
		if(fp1 == NULL){
			printf("Error opening the file output.txt"); // File error checking
			}
		while(fscanf(fp1,"%d",&n) != EOF) // there are lots of way to parse but this method is far easy for parsing, when fscanf is at the eof then it will return 0.
		{									// firstly fscanf takes the values "n" above the pairs then assign it to variable n.
			char b[n][3];			// this matrix hold the pairs in it such as (2,1) 2 is the b[i][0] , is b[i][1] and 1 is b[i][2] there is no need to parse commas in it
			fscanf(fp1,"%c",&x);   // we initially choose a random chracter and read from file, then again. after from many tests, i have decided to use that method
			fscanf(fp1,"%c",&x);    // after take all the chracters
			fgets(array,MAX_TAKE,fp1);	// in our sets, the most number of elements in set is 10 then i have calculated the comma number with them and as result i've decided to take
									// 10 elements in input.txt it can be changed as macro
			int i=0;
			while(i<n){
				fgets(b[i],5,fp1);  // Fill the matrix while reaching the pair number in the set 
				i++;
			}
		
		printPairs(b,n);		// Firstly print the pairs such as 2,1 2,3 
		reflexive(b,array,n);	 //function that prints whether a set is reflexive or not
		transitive(b,array,n);	 //function that prints whether a set is transitive or not
		antisymmetric(b,array,n);  //function that prints whether a set is antisymmetric or not
		symmetric(b,n);		// function that prints whether a set is symmetric or not
			// this process will be done until reaching EOF which is done by fscanf
			// all the functions above has it's own file pointer to print to output.txt this is why we never use fp for output.txt
	}		
	fclose(fp1);
		
		return 0 ;
	}
