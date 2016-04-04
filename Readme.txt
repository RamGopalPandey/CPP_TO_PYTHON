Instructions-> "translate.cpp takes cpp file as input and outputs corresponding translated python file."
	       "change input and output filenames in translate.cpp for conversion.

Assumption in c++ code:
1-> All code blocks like loop and conditional statements must have opening and closing curly braces.

eg: correct format			if(i==2)                                   
    					{
     					cout<<"yes";
    					}
    
    incorrect format			if(i==2)                                   
    					cout<<"yes";

2-> There is no leading space in any line of c++ code.

    correct format			if(i==2)                                   
    					{
     					cout<<"yes";
    					}
    
    incorrect format			if(i==2)
					{                                   
    						cout<<"yes";
					}
    For clarity,refer to sample cpp codes.

NOTE: This converter can transform basic c++ code to python code.
      It supports conversion of:
      *Conditional statements: if,if->else,if->elseif->else,nested conditions
      *Loop statements: for,while,nested loops
      *function declaration and definition
      *basic input (cin)
      *basic output(cout)
      *other basic things

