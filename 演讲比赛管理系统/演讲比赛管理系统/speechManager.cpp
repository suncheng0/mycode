#include"speechManager.h"
SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}
void SpeechManager::show_Menu()
{
	cout << "演讲比赛" << endl;
}
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void SpeechManager::speechDraw()
{
	cout << "第（" << this->m_Index << ")轮选手正在抽签" << endl;
	cout << "=========" << endl;
	cout << "抽签结果如下" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << "";
		}
		cout << endl;
	}
	cout << "-----" << endl;
	system("pause");
	cout << endl;
}
void SpeechManager::startSpeech()
{
	this->speechDraw();
	this->speechContest();
	this->showScore();
	this->m_Index++;
	this->speechDraw();
	this->speechContest();
	this->showScore();
	this->saveRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");

}
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i+10001,sp));
	}
}
void SpeechManager::speechContest()
{
	cout << "------第" << this->m_Index << "轮比赛正式开始------" << endl;
	multimap<double, int, greater<double>>groupScore;
	int num = 0;
	vector<int>v_src;
	if (this -> m_Index == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(),d.end(),greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(),0.0f);
		double avg = sum / (double)d.size();
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		/*cout << "编号" << *it << "姓名" << this->m_Speaker[*it].m_Name << "获取平均分" << avg << endl;*/
		groupScore.insert(make_pair(avg,*it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号" << it->second << "姓名" << this->m_Speaker[it->second].m_Name << "成绩"
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			
			groupScore.clear();
		}
	}
	cout << endl;
	cout << "第" << this->m_Index << "轮比赛完毕" << endl;
	system("pause");
}
void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}
void SpeechManager::showScore()
{
	cout << "------第" << this->m_Index << "轮晋级选手信息如下" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号" << *it << "姓名" << this->m_Speaker[*it].m_Name
			<< "得分" << this->m_Speaker[*it].m_Score[m_Index-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv",ios::out|ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	this->fileisEmpty = false;

}
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileisEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileisEmpty = true;
		return;
	}
	this->fileisEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = data.find(",",start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	for(map<int,vector<string>>::iterator it = m_Record.begin();it != m_Record.end();it++)
	{
		cout << it->first << "冠军编号" << it->second[0] << "分数" << it->second[1] << endl;
	}
}
void SpeechManager::showRecord()
{
	if (this->fileisEmpty)
	{
		cout << "文件为空或者文件不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
		cout << "第" << i + 1 << "届"
			<< "冠军编号" << this->m_Record[i][0] << "得分" << this->m_Record[i][1] << " "
			<< "亚军编号" << this->m_Record[i][0] << "得分" << this->m_Record[i][1] << " "
			<< "季军编号" << this->m_Record[i][0] << "得分" << this->m_Record[i][1] << " "
			<< endl;
		}
	}

	system("pause");
	system("cls");

}
void SpeechManager::clearRecord()
{
	cout << "是否确定清空文件" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
SpeechManager::~SpeechManager()
{

}