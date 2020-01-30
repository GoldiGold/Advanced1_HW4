//
// Created by חן גולדשטיין on 29/01/2020.
//

#include "MyClientHandler.h"

std::vector<std::string> split(const std::string &s, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

//std::vector<std::string> split(const std::string &s, char delimiter) {
//	std::vector<std::string> tokens;
//	std::string token;
//	std::istringstream tokenStream(s);
//	while (std::getline(tokenStream, token, delimiter)) {
//		tokens.push_back(token);
//	}
//	return tokens;
//}

int MyClientHandler::handleClient(int sockfd) {
	std::cout << "handling client right now" << std::endl;
	char buffer[BUFFER_SIZE];
//		std::vector<std::string> sub_n;
	std::string t;
	std::string problem;
	int counter = 0;
	int i = 0;
	do {
		// TODO: UNDERSTAND WHY WE AIN'T GETTING ANY VALUES FROM THE CLIENT (MAYBE SOMETHING WITH THE INCLUDED HEADERS)
		ssize_t size = read(sockfd, buffer, BUFFER_SIZE);
		t = buffer;
//		std::cout << buffer << std::endl;
		problem += t;
		if (t.find('\n') != std::string::npos) {
			++counter;
		}
		++i;
	} while (t.find("end") == std::string::npos);

	int endIndex = problem.find("end");
	problem.erase(endIndex, std::string::npos);
	std::vector<std::string> sub_lines = split(problem, '\n');

	int sizeee = sub_lines.size();
	std::vector<int> index_to_erase;
	int index = 0;
	for (index = 0; index < sizeee; ++index) {
//		std::cout << "line number " << index << " :" << sub_lines[index] << std::endl;
		if (sub_lines[index].length() == 0) {
			index_to_erase.push_back(index);
		}
	}
	int amount_to_erase = index_to_erase.size();
	for (int j = amount_to_erase - 1; j >= 0; --j) {
//		std::cout << "index to erase:" << index_to_erase[j] << std::endl;
//		std::cout << "the line is: " << sub_lines[index_to_erase[j]] << std::endl;
		sub_lines.erase(sub_lines.begin() + index_to_erase[j]);
	}
	// CREATING THE MATRIX
	auto mat_problem = this->createMatProblem(sub_lines);
//	for (const std::string& line: sub_lines){
//		std::cout << "after matrix creation: " << line << std::endl;
//	}
	std::string matrix_desc = mat_problem->toString();
	std::string desc_solution;

	// TODO: FIX THE INPUT FOR THE INSERTING OF TO THE CACHE - WE SEND A VECTOR OF VECTORS AND WE NEED TO SEND A STRING.
	if (this->cache_manager->is_exist(matrix_desc)) {
		std::cout << "exist already" << std::endl;
		desc_solution = this->cache_manager->get_solution(matrix_desc);
	} else {
		std::cout << "new problem" << std::endl;
		std::list<std::pair<char,int>> *solution = solver->solve(mat_problem);
		for (auto p: *solution) {
			desc_solution += directions->at(p.first) +"("+ std::to_string(p.second)+")";
			desc_solution += ',';
		}
		desc_solution.pop_back();
		desc_solution += '\n';
		this->cache_manager->insert(matrix_desc, desc_solution);
	}
	send(sockfd, desc_solution.c_str(), desc_solution.length(), 0);
//	matrix.
//	sizeee = sub_lines.size();
//	for (int indexx = 0; indexx < sizeee; ++indexx) {
//		std::cout << "line: " << sub_lines[indexx] << std::endl;
//	}

//		std::cout << problem << std::endl;
//	std::string sol = this->solver->solve("end");
//	this->cache_manager->insert("end", sol);
//		std::vector<std::string> lines = split(problem, '\n');

// TODO: REMEMBER THAT THE LAST TWO LINES ARE OF THE START-CO AND END-CO.

	std::cout << "the amount of lines is: " << counter << std::endl;
//	send(sockfd, "hello", strlen("hello"), 0);
//	send(sockfd, "fuckkkkk", strlen("fuckkkkk")/*sol.c_str(), sol.length()*/, 0);
//		write(sockfd, sol.c_str(), ((size_t)sol.length()));
	std::cout << "message was sent" << std::endl;
	close(sockfd);

//		std::cout << "solution from file: " << this->cache_manager->get_solution("end") << std::endl;

	return 1;
}
MatrixProblem *MyClientHandler::createMatProblem(const std::vector<std::string> &sub_lines) {
	std::vector<std::vector<std::string>> mat;

	mat.reserve(sub_lines.size());

	int start_index = -1;
	int end_index = -1;
	int line_index = 0;
	std::vector<std::string> temp;
	for (const std::string &line: sub_lines) {
		temp = split(line, ',');
		if (temp.size() == 2) {
			if (start_index == -1) {// the second check is the case that the start index hasn't changed
				start_index = line_index;
				std::cout << "start: " << start_index;
			} else if (end_index == -1) {
				end_index = line_index;
				std::cout << "end: " << end_index;
			}
		}
		mat.push_back(temp);
		++line_index;
		temp.clear();
	}

	int start_x = stoi(mat[start_index][0]);
	int start_y = stoi(mat[start_index][1]);
	int end_x = stoi(mat[end_index][0]);
	int end_y = stoi(mat[end_index][1]);
	mat.erase(mat.begin() + start_index, mat.end());

//	for (const std::vector<std::string> &vec: mat) {
//		for (const std::string &str : vec) {
//			std::cout << "arg: " << str;
//		}
//		std::cout << std::endl;
//	}

	std::cout << "size:::: " << mat.size() << std::endl;

	std::vector<std::vector<int>>* matrix = new std::vector<std::vector<int>>;
	std::vector<int> temp_int;
	matrix->reserve(mat.size());
	temp_int.reserve(mat[0].size()); // the length of a line - a matrix so every line is the same length.
	for (const std::vector<std::string> &vec: mat) {
		for (const std::string &arg : vec) {
			try {
				temp_int.push_back(stoi(arg));
			} catch (...) {
				temp_int.push_back(0);
			}
		}
		matrix->push_back(temp_int);
		temp_int.clear();
	}

	std::cout << "size of matrix: " << matrix->size() << std::endl;

	return new MatrixProblem(matrix, start_x, start_y, end_x, end_y);
}
MyClientHandler *MyClientHandler::clone() {
	return new MyClientHandler(this->solver, this->cache_manager);
}
//std::vector<std::string> MyClientHandler::findStartCo(std::vector<std::string> problem) {
//	int start_index = 0;
//	int end_index = 0;
//	for(int index = 0; index < problem.size(); ++index){
//
//	}
//	return std::vector<std::string>();
//}











//{
//	std::cout<< "handling client right now" << std::endl;
//	char buffer[BUFFER_SIZE];
////		std::vector<std::string> sub_n;
//	std::string t;
//	std::string problem = nullptr;
//	int counter = 0;
//	int i = 0;
//	do {
//		// TODO: UNDERSTAND WHY WE AIN'T GETTING ANY VALUES FROM THE CLIENT (MAYBE SOMETHING WITH THE INCLUDED HEADERS)
//		ssize_t size = read(sockfd, buffer, BUFFER_SIZE);
//		t = buffer;
//		std::cout << buffer << std::endl;
//		problem.append(buffer);
//		if (t.find('\n') != std::string::npos) {
//			++counter;
//		}
//		++i;
//		std::cout << i << std::endl;
////			sub_n = split(t, "\n");
//	} while (t.find("end") == std::string::npos);
//
//	int endIndex = problem.find("end\n");
//	problem.erase(endIndex, strlen("end\n"));
//
//	std::cout << problem << std::endl;
////	std::string sol = this->solver->solve("end");
////	this->cache_manager->insert("end", sol);
//	std::vector<std::string> lines = split(problem, '\n');
//
//// TODO: REMEMBER THAT THE LAST TWO LINES ARE OF THE START-CO AND END-CO.
//
//	std::cout << "the amount of lines is: " << counter << std::endl;
//	send(sockfd, "hello", strlen("hello"), 0);
//	send(sockfd, "fuckkkkk", strlen("fuckkkkk")/*sol.c_str(), sol.length()*/, 0);
////		write(sockfd, sol.c_str(), ((size_t)sol.length()));
//	std::cout << "message was sent" << std::endl;
//	close(sockfd);
//
////		std::cout << "solution from file: " << this->cache_manager->get_solution("end") << std::endl;
//
//	return 1;
//}











//int MyClientHandler::handleClient(int sockfd) {
//	char buffer[BUFFER_SIZE];
////		std::vector<std::string> sub_n;
//	std::string t;
//	int counter = 0;
//	int i = 0;
//	do {
//		ssize_t size = read(sockfd, buffer, BUFFER_SIZE);
//		t = buffer;
////			std::cout << buffer << std::endl;
//		if (t.find('\n') != std::string::npos) {
//			++counter;
//		}
//		++i;
////			sub_n = split(t, "\n");
//	} while (t.find("end") == std::string::npos);
////	std::string sol = this->solver->solve("end");
////	this->cache_manager->insert("end", sol);
//
//	std::cout << "the amount of lines is: " << counter << std::endl;
//	send(sockfd, "hello", strlen("hello"), 0);
////	send(sockfd, sol.c_str(), sol.length(), 0);
////		write(sockfd, sol.c_str(), ((size_t)sol.length()));
//	std::cout << "message was sent" << std::endl;
//	close(sockfd);
//
//	std::cout << "solution from file: " << this->cm->get_solution("end") << std::endl;
//
//	return 1;
//}
