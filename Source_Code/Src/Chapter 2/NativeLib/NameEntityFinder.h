#pragma once

enum NameEntityType
{
	PersonName,
	PlaceName,
	OrganizationName
};

typedef struct _NAMEENTITY
{
	wchar_t* _name;
	NameEntityType _type;
	int _highlight_begin;
	int _highlight_length;
	double _score;
}NAMEENTITY, *PNAMEENTITY;

class CNameEntityFinder
{
private:
	NameEntityType _type;
public:
	CNameEntityFinder(NameEntityType type);
	~CNameEntityFinder(void);
	bool Initialize(const wchar_t* resourcePath);
	void UnInitialize();
	bool FindNames(const wchar_t* text, 
		PNAMEENTITY* ppNameEntity,
		UINT* nameCount);

private:
	int PopulateResult(const wchar_t* text, PNAMEENTITY* ppNameEntity);
	void AddNameEntity(const wchar_t* name, int beginPosition, NameEntityType type, double score, PNAMEENTITY entity);
};
