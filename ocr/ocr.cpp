#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// input file specifications
const int digitHeight = 3;
const int digitWidth = 3;
const int digitCount = 9;

// representations of in the file format
constexpr char repr1[9] = {
  ' ', ' ', ' ',
  ' ', ' ', '|',
  ' ', ' ', '|'
};
constexpr char repr2[9] = {
  ' ', '_', ' ',
  ' ', '_', '|',
  '|', '_', ' '
};
constexpr char repr3[9] = {
  ' ', '_', ' ',
  ' ', '_', '|',
  ' ', '_', '|'
};
constexpr char repr4[9] = {
  ' ', ' ', ' ',
  '|', '_', '|',
  ' ', ' ', '|'
};
constexpr char repr5[9] = {
  ' ', '_', ' ',
  '|', '_', ' ',
  ' ', '_', '|'
};
constexpr char repr6[9] = {
  ' ', '_', ' ',
  '|', '_', ' ',
  '|', '_', '|'
};
constexpr char repr7[9] = {
  ' ', '_', ' ',
  ' ', ' ', '|',
  ' ', ' ', '|'
};
constexpr char repr8[9] = {
  ' ', '_', ' ',
  '|', '_', '|',
  '|', '_', '|'
};
constexpr char repr9[9] = {
  ' ', '_', ' ',
  '|', '_', '|',
  ' ', '_', '|'
};
constexpr char repr0[9] = {
  ' ', '_', ' ',
  '|', ' ', '|',
  '|', '_', '|'
};
// collection of representations- position in array corresponds to value
// representation above.
const char * reprs[10] = {
  repr0, repr1, repr2, repr3, repr4,
  repr5, repr6, repr7, repr8, repr9,
};

class Digit {
  int buffLen = digitHeight * digitWidth;
  char * dBuff;
  int buffPtr = 0;

  public:
  Digit() { dBuff = new char[buffLen]; }
  ~Digit() { delete [] dBuff; }

  // add adds a character to the underlying character buffer.
  void add(char c) {
    if ( buffPtr == buffLen ) { return; }
    dBuff[buffPtr++] = c;
  }

  // parse returns the integer value for the digit stored in the underlying
  // character buffer. The imprint values above are used to determine the
  // numerical value.
  int parse() {
    for ( int j = 0; j <= 9; ++j ) {
      bool found = true;
      for ( int i = 0; i < buffLen; ++i ) {
        if ( reprs[j][i] != dBuff[i] ) { found = false; break; }
      }
      if ( found ) { return j; }
    }
    return -1;
  }
};

struct AccountScanner {
  // scanner internals
  int buffPtr = 0;
  std::string lineBuffs[digitHeight];

  // methods
  AccountScanner( std::ifstream & f ) {
    // allocate and populate line buffers
    std::string line;
    for ( int i = 0; i < digitHeight; ++i ) {
      // todo: check if read fails, throw an exception
      std::getline( f, line );
      lineBuffs[i] = line;
    }
  }

  // scanDigit attempts to scan a digit from the line buffer. It reads
  // digitWidth characters from the line buffers and moves the buffPtr forward.
  // If the digit cannot be parsed, -1 is returned, otherwise the return value
  // is either 0 or a positive single digit number.
  int scanDigit() {
    Digit d;
    for ( int i = 0; i < digitHeight; ++i ) {
      for ( int j = buffPtr; j < buffPtr + digitWidth; ++j ) {
        d.add( lineBuffs[i][j] );
      }
    }
    // increment buffPtr
    buffPtr += digitWidth;
    return d.parse();
  }
};

// overload stream output operator to print line buffer contents for scanner
std::ostream & operator<<( std::ostream & out, const AccountScanner & s ) {
  for ( int i = 0; i < digitHeight; ++i ) {
    out << s.lineBuffs[i] << std::endl;
  }
  return out;
}

// readAcctFile creates a scanner for the given input file stream and attempts
// to parse the contained account number.
void readAcctFile( std::ifstream & f ) {
  AccountScanner scanner = AccountScanner( f );
  std::ostringstream acctNum;
  for ( int i = 1; i <= digitCount; ++i ) {
    int scanned = scanner.scanDigit();
    if ( scanned < 0 ) { std::cout << "invalid" << std::endl; return; }
    acctNum << scanned;
  }
  std::cout << acctNum.str() << std::endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void usage() {
  std::cout << "usage: ocr <filename>" << std::endl;
  std::exit(1);
}

void fileErr() { std::cout << "error: file unreadable" << std::endl; }

int main(int argc, char** argv) {
  // verify that filename was provided over the command line args
  if ( argc != 2 ) { usage(); }

  // open file specified and read out account
  std::ifstream f { argv[1] };
  if ( ! f ) { fileErr(); }
  readAcctFile( f );
}
