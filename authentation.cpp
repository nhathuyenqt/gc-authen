#include <iostream>
#include <string>
#include <typeinfo>
#include "emp-tool/emp-tool/emp-tool.h"
#include "garbling_scheme.cpp"
using namespace std;
using namespace emp;
using std::cout;
using std::endl;

class Authentication{
    vector<block> encoding_info;
	vector<bool> decoding_info;
	vector<block> encoded_input;
	vector<bool> input(64);
	vector<block> encoded_output;
	vector<bool> output;

    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    // uniform_int_distribution<int> dist (0, 1);
    auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    
    // auto gen = [&dist, &mersenne_engine](){
    //                return dist(mersenne_engine);

    generate(begin(input), end(input), gen);
    
    // Optional
    for (auto i : input) {
        cout << i << " ";
    }
    
	//string gc_filename = "circuits/garbled_adder_32bit";
	string gc_filename = "adder_32bit.txt";
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

    void generate_input(){
        
    }
}