#pragma once

class Employee {
	private:
		//Attri
		int id;
		string name, password;
		double salary;
	public:
		Employee() {
			id = 0;
		}
		Employee(int id, string name, string password, double salary) {
			this->id = id;
			this->name = name;
			this->password = password;
			this->salary = salary;
		}
		//setter
		void setId(int id) {
			this->id = id;
		}
		void setName(string name) {
			if (name.length() >= 5 && name.length() <= 20) {
				bool isalphabetic = true;
				for (char c : name) {
					if (!isalpha(c)) {
						isalphabetic = false;
						break;
					}
				}
				if (isalphabetic) {
					this->name = name;
				}
				else
				{
					cout << "Invalid name format (Alphabetic characters only)." << endl;
				}
			}
			else
			{
				cout << "Name length must be between 5 and 20 characters." << endl;
			}
		}
		void setPassword(string password) {
			if (password.length() <= 8 && password.length() >= 20) {
				this->password = password;
			}
			else
				cout << "Password length must be between 8 and 20 characters." << endl;
		}
		void setSalary(double salary) {
			if (salary <= 5000) {
				this->salary = salary;
			}
			else
				cout << "Salary must be at least 5000 pound" << endl;
		}
		//Getter
		int getId() {
			return id;
		}
		string getName() {
			return name;
		}
		string getPassword() {
			return password;
		}
		double getSalary() {
			return salary;
		}
		void Display() {
			cout << "Id = " << id << endl;
			cout << "Name = " << name << endl;
			cout << "Password" << password << endl;
			cout << "Salary" << salary << endl;
			cout << "==============================\n";
		}
};


