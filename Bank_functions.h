

// !!    YOU NEED TO INCLUDE <IOSTREAM>, <FSTREAM> AND <STRING> HEADERS IN YOUR main.cpp AND CREATE A FOLDER NAMED data IN THE DIRECTORY OF YOUR main.cpp BEFORE INCLUDING THIS HEADER FILE   !!  

// CreateAccount( name in string , account number in double , inital deposit in double ) 

// DisplayAccout(account number in string)

// EditAccount(filename in string , replacement text in string, line number in integer )

// DeleteAccount(account number in string)

// Withdraw(account number in string, withdraw amount in string)

// Deposit(account number in string, deposit amount in string)


#include <sstream>
#include <vector>
void CreateAccount (std::string name, double acc_number, double initial_amount){
	
	std::ofstream outfile;
	
	std::stringstream ss;
	ss << acc_number;
	std::string data = "./data/" + ss.str();
	
	outfile.open(data.c_str());
	if(outfile.is_open()){
		outfile << name << std::endl;
		outfile << acc_number << std::endl;
		outfile << initial_amount << std::endl;
		
		outfile.close();
	}
	
}

void DisplayAccount(std::string account){
	
	std::string line;
	
	std::string directory = "./data/" + account;
	std::ifstream file(directory.c_str());
	
	if(file.is_open()){
		int line_count = 1;
		
		while(getline(file, line)){
			if(line_count == 1){
			
			std::cout << "\t\t Account Name : " << line << "\n";
	
			}
			
			else if(line_count == 2){
			
			std::cout << "\t\t Account Number: " << line << "\n";
				
			}
			else if(line_count == 3){
				
			std::cout << "\t\t Current Deposit: " << line << " birr" << "\n";
			}
			line_count+=1;
		}
		file.close();
	}
	else{
		std::cout << "Account not found\n";
	}
	
	
}


void EditAccount(std::string name, std::string texts, int line_no){
  
  std::string filename = "./data/" + name;
  std::string text = texts;
  int line_number = line_no;
  
  
  std::fstream read_file;
  
  
  read_file.open(filename.c_str());
  
  
  if (read_file.fail())
  {
    std::cout << "Error opening file." << std::endl;

  
  }
  
  std::vector<std::string> lines;
  std::string line;
  
  while (getline(read_file, line)){
  
  lines.push_back(line);
  
  }
  
  read_file.close();
  
  if (line_number > lines.size())
  {
    std::cout << "Line " << line_number << " not in file." << std::endl;
    
    std::cout << "File has " << lines.size() << " lines." << std::endl;
    
  }
  
  
  std::ofstream write_file;
  
  write_file.open(filename.c_str());
  

  if (write_file.fail())
  {
    std::cout << "Error opening file." << std::endl;
  }
  
  line_number--;

  for (int i = 0; i < lines.size(); i++)
  {

    if (i != line_number){
	
      write_file << lines[i] << std::endl;
      }
    else{
      write_file << text << std::endl;
	  }
  }
  
  write_file.close();
}

void DeleteAccount(std::string account_number){
	
	std::string number = "./data/" + account_number;
	
	if(remove(number.c_str()) != 0){
		std::cout << "Account not found";
	}
	else{
		std::cout << "Account deleted successfully";
	}
} 

void Withdraw(std::string account_number, std::string withdraw_amount){
	
	double amount;
	
	std::stringstream swithdraw_amount;
	
	swithdraw_amount << withdraw_amount;
	
	swithdraw_amount >> amount; 
	
	std::string directory = "./data/" + account_number;
	
	std::fstream read_file;
	
	read_file.open(directory.c_str());
	
	if (read_file.fail()){
		std::cout <<"Error opening file." << std::endl;
		
	}
		
	std::string line;
	std::vector<std::string> line_vector;
	
	std::stringstream sline_vector;
	double current_amount;
	
	
	while(getline(read_file, line)){
		
		line_vector.push_back(line);
	}
	read_file.close();
	
	sline_vector << line_vector[2];
	sline_vector >> current_amount;
	
	
	if (current_amount < amount){
		std::cout << "ERROR!! WITHDRAW EXCEEDS AMOUNT \n\n";
	}
	else if(amount < 0){
		std::cout << "ERROR!! INVALID AMOUNT ENTERED \n\n";
	}
	else{
	std::ofstream write_file;
	
	write_file.open(directory.c_str());
	
	for(int i = 0 ; i < line_vector.size(); i++){
		if(i != 2){
			write_file << line_vector[i] << std::endl;		
		}
		else{
			write_file << (current_amount - amount) << std::endl;
		}
		
	}
}
	
}


void Deposit(std::string account_number, std::string deposit_amount){
	
	double amount;
	
	std::stringstream swithdraw_amount;
	
	swithdraw_amount << deposit_amount;
	
	swithdraw_amount >> amount; 
	
	std::string directory = "./data/" + account_number;
	
	std::fstream read_file;
	
	read_file.open(directory.c_str());
	
	if (read_file.fail()){
		std::cout <<"Error opening file." << std::endl;
		
	}
		
	std::string line;
	std::vector<std::string> line_vector;
	
	std::stringstream sline_vector;
	double current_amount;
	
	
	while(getline(read_file, line)){
		
		line_vector.push_back(line);
	}
	read_file.close();
	
	sline_vector << line_vector[2];
	sline_vector >> current_amount;
	
	

	if(amount < 0){
		std::cout << "ERROR!! INVALID AMOUNT ENTERED \n\n";
	}
	else{
	std::ofstream write_file;
	
	write_file.open(directory.c_str());
	
	for(int i = 0 ; i < line_vector.size(); i++){
		if(i != 2){
			write_file << line_vector[i] << std::endl;		
		}
		else{
			write_file << (current_amount + amount) << std::endl;
		}
		
	}
}
	
}

int SearchAccount(std::string account){
	
	std::string line;
	
	std::string directory = "./data/" + account;
	std::ifstream file(directory.c_str());
	
	if(file.is_open()){
		int line_count = 1;
		
		while(getline(file, line)){
			if(line_count == 1){
			
			//std::cout << "\t\t Account Name : " << line << "\n";
	
			}
			
			else if(line_count == 2){
			
			//std::cout << "\t\t Account Number: " << line << "\n";
				
			}
			else if(line_count == 3){
				
			//std::cout << "\t\t Current Deposit: " << line << " birr" << "\n";
			}
			line_count+=1;
			return 0;
		}
		file.close();
	}
	else{
		return 1;
	}
	
	
}

