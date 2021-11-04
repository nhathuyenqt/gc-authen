#include <iostream>
#include <string>

#include "garbling-scheme.cpp"

using std::cout;
using std::endl;
//--------------------------------------------------------------------------------------------------------------------------

// trying to find cause of segfault in circuits/circuit_file.h problem is that the fopen call fails. debugging code in file_io_channel.h and circuit_file.h -> use absolute path?

//--------------------------------------------------------------------------------------------------------------------------


int main(int argc, char** argv) {
	vector<block> encoding_info;
	vector<bool> decoding_info;
	vector<block> encoded_input;
	vector<bool> input(64, false);
	vector<block> encoded_output;
	vector<bool> output;
	//string gc_filename = "circuits/garbled_adder_32bit";
	string gc_filename = "garbled_adder_32bit.txt";
	string circuit_filename = "emp-tool/emp-tool/circuits/files/bristol_format/adder_32bit.txt";
	garble(&encoding_info, &decoding_info, gc_filename, circuit_filename);
	encode(&encoded_input, input, encoding_info);
	evaluate(&encoded_output, encoded_input, gc_filename, circuit_filename);
	decode(&output, encoded_output, decoding_info);
	
	for (size_t i=0; i<output.size(); i++) {
	    if (output[i] == true) {
	        cout << "1";
	    }
	    else {
	        cout << "0";
	    }
	}
	cout << endl;
}
