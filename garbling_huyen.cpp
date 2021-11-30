// #include <iostream>
// #include <string>
// #include <typeinfo>
// #include "emp-tool/emp-tool/emp-tool.h"
// using namespace std;
// using namespace emp;
// using std::cout;
// using std::endl;

// /*
// * Parameters:
// * Inputs:
// *   circuit_filename: name of the file that contains the circuit in Bristol Format (e.g. "ham.txt")
// * Outputs:
// *   encoding_info: vector of <block> with n+1 elements, where n is the number of input wires. encoding_info[0] contains the GC's delta value. After that come all input wire labels
// *   decoding_info: vector of <bool> with n elements. decoding_info[i] = lsb(output[i])
// *   gc_filename: the name of the file to which the garbled circuit is written
// */
// void garble(vector<block>* encoding_info, vector<bool>* decoding_info, const string& gc_filename, const string& circuit_filename) {
//     FileIO* file_io = new FileIO(gc_filename.c_str(), false);   //do I ever delete this?
//     HalfGateGen<FileIO>::circ_exec = new HalfGateGen<FileIO>(file_io);
//     BristolFormat cf(circuit_filename.c_str());
//     encoding_info->resize(cf.n1+cf.n2+1);
//     decoding_info->resize(cf.n3);
//     block* input_1 = new block[cf.n1];
// 	block* input_2 = new block[cf.n2];
// 	block* output = new block[cf.n3];
// 	PRG prg;
// 	prg.random_block(input_1, cf.n1);
// 	prg.random_block(input_2, cf.n2);
// 	//garble the circuit
// 	cf.compute(output, input_1, input_2);
// 	//write decoding info
// 	for(size_t i=0; i<cf.n3; i++) {
// 	    (*decoding_info)[i] = getLSB(output[i]);
// 	}
// 	//write encoding info
// 	(*encoding_info)[0] = ((HalfGateGen<FileIO>*) HalfGateGen<FileIO>::circ_exec)->delta;
// 	cout<<"tesht "<<typeid((*encoding_info)[0]).name() << endl;
// 	for (size_t i=0; i<cf.n1; i++) {
// 	    (*encoding_info)[i+1] = input_1[i];
// 	}
// 	for (size_t i=0; i<cf.n2; i++) {
// 	    (*encoding_info)[cf.n1+1+i] = input_2[i];
// 	}

// 	delete HalfGateGen<FileIO>::circ_exec;
// 	delete file_io;
// 	delete[] input_1;
// 	delete[] input_2;
// 	delete[] output;
// }

// /*
// * Parameters:
// * Inputs:
// *   input: the input bits for the garbled circuit. these bits will be encoded.
// *   encoding_info: the encoding information that has been output by the garble function.
// * Outputs:
// *   encoded_input: the input wire labels for the garbled circuit (the encoded input)
// */
// void encode(vector<block>* encoded_input, const vector<bool>& input, const vector<block>& encoding_info) {
// encoded_input->resize(input.size());
// //pseudocode
// //if input[i] = FALSE
// //  output[i] = encoding_info[i+1]
// //else
// //  output[i] = encoding_info[i+1] XOR encoding_info[0]
// for(size_t i=0; i<input.size(); i++){
// 	if (input[i] == false) {
//         (*encoded_input)[i] = encoding_info[i+1];
//     }
// 	else {
// 	    (*encoded_input)[i] = encoding_info[i+1] ^ encoding_info[0];
// 	}
// }
// cout << endl;




// }

// /*
// * Parameters:
// * Inputs:
// *   encoded_input: the encoded input (the wire labels) for the garbled circuit, which was output by the encode function
// *   gc_filename: the name of the file that contains the garbled circuit
// *   circuit_filename: the name of the file that contains the circuit in Bristol Format
// * Outputs:
// *   encoded_output: the output wire labels of the garbled
// */
// void evaluate(vector<block>* encoded_output, const vector<block>& encoded_input, const string& gc_filename, const string& circuit_filename) {
// 	block tmp;
//     FileIO* file_io = new FileIO(gc_filename.c_str(), true);

//     HalfGateEva<FileIO>::circ_exec = new HalfGateEva<FileIO>(file_io);

//     // weird to require the circuit file to be known. Would be nicer to have one sufficient "garbled" file
//     BristolFormat cf(circuit_filename.c_str());
//     encoded_output->resize(cf.n3);
//  	cf.compute(encoded_output->data(), encoded_input.data(), encoded_input.data() + cf.n1);

// 	delete HalfGateEva<FileIO>::circ_exec;
// 	delete file_io;
// }

// /*
// * Parameters:
// * Inputs:
// *   encoded_output: the output labels which have been output by the evaluate function.
// *   decoding_info: the decoding information that has been output by the garble function.
// * Outputs:
// *   output: the decoded output of the garbled circuit.
// */
// void decode(vector<bool>* output, const vector<block>& encoded_output, const vector<bool>& decoding_info) {
//     output->resize(encoded_output.size());
// //pseudocode
// //output[i] = decoding_info[i] XOR getLSB(labels[i])
// for(size_t i=0; i<decoding_info.size(); i++){
//     (*output)[i] = decoding_info[i] ^ getLSB(encoded_output[i]);
// }

// }
