#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

struct Rectangle {
int width ;
int height ;
} ;
enum CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID

} ;

vector<Rectangle> T;

const CommandKind getCommandKind(string s){
	if(s == "ADD")	return ADD;
	if(s == "SORT")	return SORT;
	if(s == "PRINT")	return PRINT;
	if(s == "CLEAR")	return CLEAR;
	if(s == "EXIT")	return EXIT;	
}

Rectangle getRectangle(){
	Rectangle R;
	cin >> R.height;//cin으로 받기 
	cin >> R.width;
	return R;
	
}

bool sort_by_hieght( const Rectangle & lhs, const Rectangle & rhs )
{
   return lhs.height < rhs.height;
}

void print(vector<Rectangle> rectangles){
	vector<Rectangle>::iterator iter=rectangles.begin();
	
	for (iter = rectangles.begin(); iter != rectangles.end(); ++iter){
        cout << iter->height << endl;
        cout << iter->width << endl;
        
    }

}

int main() {
	vector<Rectangle> rectangles ;
	while ( true ) {
		string commandString;
		cin >> commandString;
		const CommandKind command = getCommandKind(commandString) ;
		switch ( command ) {
			case ADD : {
				const Rectangle& newRectangle = getRectangle() ;
				rectangles.push_back(newRectangle) ;
				break ;
			}
			case PRINT:
			print(rectangles);




			// use const_iterator in print()
			// define and call print(const Rectangle&)
				break ;
			case SORT: {
			sort(rectangles.begin(),rectangles.end(),sort_by_hieght) ; // define and call swap in sort()
			//print(rectangles) ;
			break ;
			}	
			case CLEAR: rectangles.clear() ; break ;
			case EXIT: break ;
			default: assert (false) ; break ;
			}
			if ( command == EXIT ) break ;
			}
}


