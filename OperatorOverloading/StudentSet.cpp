/*
 * StudentSet.cpp
 *
 *  Created on: Dec 24, 2016
 *      Author: alex
 */

#include "StudentSet.h"
int StudentSet::sizeAll=0;
StudentSet** StudentSet::all=new StudentSet*[0];
void StudentSet::deleteprintAll(StudentSet* newSet ){
	StudentSet** allNew=new StudentSet*[sizeAll-1];
	if(newSet->index==sizeAll-1){
		//StudentSet** allNew=new StudentSet*[sizeAll-1];
		for(int i=0;i<sizeAll-1;i++){
			allNew[i]=all[i];
			allNew[i]->index=i;
		}
		delete all;
		all=allNew;
		sizeAll--;
	}
	else if( sizeAll!=0){
	StudentSet** allNew=new StudentSet*[sizeAll-1];
	for(int i=0;i<newSet->index;i++){
		allNew[i]=all[i];
	}
	allNew[newSet->index]=all[sizeAll-1];
	allNew[newSet->index]->index=all[sizeAll-1]->index;
	for(int i=newSet->index+1;i<sizeAll-1;i++){
		allNew[i]=all[i];
		allNew[i]->index=i;
	}
	//delete[] all;
	all=allNew;
	sizeAll--;
	/*if(sizeAll==0)
		delete[] all;*/
	}

		//delete newSet;
}
void StudentSet::addprintAll(StudentSet* newSet){
		StudentSet** allnew=new StudentSet*[sizeAll+1];

			for(int i=0;i<sizeAll;i++){
				allnew[i]=all[i];
			}

		allnew[sizeAll]=newSet;
		delete all;
		all=allnew;

	sizeAll++;
}
void StudentSet::printAll(){
	cout<<sizeAll<<endl;
	for(int i=0;i<sizeAll;i++){
		cout<<*all[i];
	}
}
StudentSet::StudentSet(const Student* s,int Size){
	StudentSet* newSet=new StudentSet();
	for(int i=0;i<Size;i=i+1){
			newSet->Add(s[i]);
		}
	/*if(size>0)
		deleteprintAll(this);*/
	if(index>sizeAll)
			index=sizeAll-1;
	else
		index=newSet->index;
	size=newSet->size;
	set=new Student*[size];
	for(int i=0;i<size;i=i+1){
				set[i]=new Student(*(newSet->set[i]));
			}
	delete newSet;

	addprintAll(this);
}
StudentSet::StudentSet():size(0),set(NULL){
	index=sizeAll;
	addprintAll(this);

}
StudentSet::~StudentSet() {
	if(sizeAll!=0){
	StudentSet::deleteprintAll(this);
	if(set!=NULL){
	for(int i=0;i<size;i=i+1){
				delete this->set[i];
			}
			delete[] this->set;
			set=NULL;
		//size=0;
	}
	size=0;
	}


}
bool StudentSet::Add(const Student& s)
{
	if(size!=0){
		int j;
		for(j=0; j<size; j++)
			if(set[j]->ID == s.ID)
				return false;
	}
	Student** temp;
	temp = new Student*[size+1];
	if (!temp)
		return false;
	if(size!=0){
	int i;
	for(i=0; i<size; i++)
		temp[i]=set[i];
	}
	temp[size] = new Student(s);
	delete[]set;
	set=temp;
	size++;
	return true;
}

StudentSet& StudentSet::operator=(const StudentSet& sSet){
/*	if (set!=NULL){
	for(int i=0;i<size;i++){
		delete set[i];
	}

	delete[] set;
	}*/
	/*if(this->set!=NULL&&size>0){
		for(int i=0;i<size;i++){
			delete set[i];
		}
		delete[] set;

	}*/

	this->size=sSet.size;
	this->set=new Student*[size];
	for(int i=0;i<sSet.size;i++){
		this->set[i]=new Student(*(sSet.set[i]));
	}
	return *this;
}
ostream&  operator<<(ostream& out, const StudentSet& s){
	return s.Show(out);
}
ostream& StudentSet::Show(ostream& out) const {
	if(this->size==0){
		out<<"{0}"<<endl;
	}
	else if(size==1){
		out<<"{"<<size<<", "<<*set[0]<<"}"<<endl;
	}
	else{

		for(int i=0;i<size;i=i+1){
			if(i==0){
				out<<"{"<<size<<", "<<*set[i]<<", ";
			}
			else if(i==this->size-1){
				out<<*set[i]<<"}"<<endl;

			}
			else{
			out<<*set[i]<<", ";
			}

		}

	}
	return out;
}
StudentSet StudentSet::operator+(const StudentSet &newSet)const{
	StudentSet* returnSet=new StudentSet();
	for(int i=0;i<this->size;i++){
		returnSet->Add(*(this->set[i]));
	}
	for(int i=0;i<newSet.size;i++){
			returnSet->Add(*(newSet.set[i]));
		}
	return *returnSet;
}
StudentSet& StudentSet::operator+=(const StudentSet &newSet){
	StudentSet *temp;
	temp=new StudentSet(*this+newSet);
	//delete this;
	*this=*temp;
	delete temp;
	return *this;
}
StudentSet StudentSet::operator/(const StudentSet &newSet)const{


	int counter=0;
	for(int i=0;i<newSet.size;i++){
		for(int j=0;j<this->size;j++){
			if(newSet.set[i]->ID==this->set[j]->ID)
				counter++;
		}
	}
	Student* sSet=new Student[counter];
	int k=0;
	for(int i=0;i<newSet.size;i++){
			for(int j=0;j<this->size;j++){
				if(newSet.set[i]->ID==this->set[j]->ID){
					sSet[k]= *(new Student(*newSet.set[i]));
					k++;
				}
			}
		}
	StudentSet *finalSet=new StudentSet(sSet,counter);

	delete[] sSet;
	return *finalSet;

}
StudentSet& StudentSet::operator/=(const StudentSet &newSet){
	*this=*this/newSet;
	return *this;
}
StudentSet StudentSet::operator-(const StudentSet &newSet)const{
	int counter=0;
	bool check=true;
		for(int i=0;i<this->size;i++){
			for(int j=0;j<newSet.size&& check;j++){
				if(this->set[i]->ID==newSet.set[j]->ID )
					check=false;

			}
			if(check)
				counter++;
			else
				check=true;
		}

		Student* sSet=new Student[counter];
		int k=0;
		for(int i=0;i<this->size;i++){
			for(int j=0;j<newSet.size&& check;j++){
				if(this->set[i]->ID==newSet.set[j]->ID )
					check=false;

			}
			if(check){
				sSet[k]= *(new Student(*this->set[i]));
				k++;
			}
			else
				check=true;
		}
		StudentSet *finalSet=new StudentSet(sSet,counter);
		finalSet->index--;
		delete[] sSet;
		return *finalSet;
}
StudentSet& StudentSet::operator-=(const StudentSet &newSet){
	*this=*this-newSet;
		return *this;
}

//get the size of the studentset
int StudentSet::operator+()const{
	return this->size;
	}
//x=operator[]
Student& StudentSet::operator[](int index){
	return *set[index];
}
//operator[]=x
const Student& StudentSet::operator[](int index)const{
	return *set[index];
}
//return true if the other studentset equal
bool StudentSet::operator==(const StudentSet& other)const{
	if(size!=other.size)
		return false;
	int i,j,counter=0;
	for(i=0; i<size; i++)
		for(j=0; j<other.size; j++)
			if (set[i]->ID==other[j].ID)
				counter++;
	if(counter==size)
		return true;
	else return false;
}
//return true if the other studentset is not equal
bool StudentSet::operator!=(const StudentSet& other)const{
	if(size!=other.size)
		return true;
	int i,j,counter=0;
	for(i=0; i<size; i++)
		for(j=0; j<other.size; j++)
			if (set[i]->ID==other[j].ID)
				counter++;
	if(counter!=size)
		return true;
	else return false;
}
