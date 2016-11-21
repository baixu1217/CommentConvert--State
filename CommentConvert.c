#include"CommentConvert.h"

StateType state;

void ConvertWork(FILE *read, FILE *write)
{
	 state = NULL_STATE;
	 while(state != END_STATE)
	 {
		switch(state)
		{
			case NULL_STATE:
				    DoNullState(read,write);
				    break;
			case C_STATE:
					DoCState(read,write);
					break;
			case CPP_STATE:
					DoCppState(read,write);
					break;
		}
	 }
}


void DoCState(FILE* read,FILE* write)
{
	 int first = fgetc(read);
	 int second = 0;
	 int third = 0;
	 switch(first)
	 {
		case '*':
			  second = fgetc(read);
			  if(second == '/')
			  {
				  third = fgetc(read);
				  if(third == '\n')
				  {
					  ungetc(third,read);
				  }
				  else
				  {
					  ungetc(third,read);
					  fputc('\n',write);
				  }
				  state = NULL_STATE;
			   }
			   else if(second == '*')
			  {
				   int third = 0;
				   third = fgetc(read);
				   if(third == '/')
				   {
						fputc(first,write);
						state = NULL_STATE;
				   }
				   else
				   {
						fputc(first,write);
						fputc(second,write);
				   }
			  }
			  else
			  {
				   fputc(first,write);
				   fputc(second,write);
			  }
			  break;
		case '\n':
			  fputc(first,write);
			  fputc('/',write);
			  fputc('/',write);
			  state = NULL_STATE;
			  break;
	    case EOF:
			  fputc(first,write);
			  state = END_STATE;
			  break;
		default:
			  fputc(first,write);
			  break;
	  }
}

void DoCppState(FILE* read,FILE* write)
{
	 int first = 0;
	 first = fgetc(read);
	 switch(first)
	 {
		 case '\n':
			  fputc(first,write);
			  state = NULL_STATE;
			  break;
		 case EOF:
			  state = END_STATE;
			  break;
		 default:
			  fputc(first,write);
			  break;
	 }
}
void DoNullState(FILE* read,FILE* write)
{
	 int first = fgetc(read);
	 int second = 0;
	 switch(first)
	 {
		 case '/':
			  second = fgetc(read);
			  if(second == '*')
			  {
				   fputc(first,write);
				   fputc('/',write);
				   state = C_STATE;
			  }
			  else if(second == '/')
			  {
				   fputc(first,write);
				   fputc(second,write);
				   state = CPP_STATE;
			  }
			  else
			  {
				   fputc(first,write);
				   fputc(second,write);
			  }
			  break;
		 case EOF:
			  fputc(first,write);
			  state = END_STATE;
			  break;
		 default:
			  fputc(first,write);
			  break;
	 }
}
void CommentConvert()
{
	 FILE *pRead = fopen(INPUTFILENAME,"r");
	 FILE *pWrite = NULL;
	 if(pRead == NULL)
	 {
		  perror("open file  for read:");
		  exit(EXIT_FAILURE);
	 }
	 pWrite =  fopen(OUTPUTFILENAME,"w");
	 if(pWrite == NULL)
	 {
		  fclose(pRead);
		  perror("open file for write:");
		  exit(EXIT_FAILURE);
	 }
	 ConvertWork(pRead,pWrite);
	 fclose(pRead);
	 fclose(pWrite);
}