#pragma once
#include "Singleton.h"
#include "Actor.h"

class ActorManager
{
	set<AActor*> allActors;
	multimap<string, AActor*> actorsName;

public:
	FORCEINLINE void AddActor(AActor* _actor)
	{
		allActors.insert(_actor);
		AddActorName(_actor);
		_actor->BeginPlay();
	}
	FORCEINLINE void RemoveActor(AActor* _actor)
	{
		allActors.erase(_actor);
		RemoveActorName(_actor);
	}
	FORCEINLINE set<AActor*> GetAllActors() const
	{
		return allActors;
	}

	FORCEINLINE void AddActorName(AActor* _actor)
	{
		actorsName.insert({ _actor->GetName(), _actor });
	}
	FORCEINLINE void RemoveActorName(AActor* _actor)
	{
		const string& _actorName = _actor->GetName();
		using Iterator = multimap<string, AActor*>::iterator;
		const pair<Iterator, Iterator>& _results = actorsName.equal_range(_actorName);

		for (Iterator _it = _results.first; _it != _results.second; )
		{
			if (_it->second == _actor)
			{
				actorsName.erase(_it++);
				break;
			}

			++_it;
		}
	}
	FORCEINLINE string GetDisplayName(AActor* _actor)
	{
		RemoveActorName(_actor);
		AddActorName(_actor);
		return GetAvailableName(_actor->GetName());
	}
	FORCEINLINE string GetAvailableName(const string& _name, const int _index = 1)
	{
		// Je rajoute "_index" au nom actuel
		const string& _fullName = _name + (_index == 0 ? "" : "_" + to_string(_index));

		// Je parcours tous les Actors qui poss�dent le m�me nom 
		using Iterator = multimap<string, AActor*>::iterator;
		const pair<Iterator, Iterator>& _results = actorsName.equal_range(_name);
		if (actorsName.empty() || _results.first == _results.second) return _name;
		bool _isFindSameName = false;
		for (Iterator _it = _results.first; _it != _results.second; ++_it)
		{
			// Si c'est le m�me
			if (_it->second->GetDisplayName() == _fullName)
			{
				_isFindSameName = true;
				break;
			}
		}

		if (!_isFindSameName)
		{
			return _fullName;
		}

		// Je reteste avec l'index suivant
		return GetAvailableName(_name, _index + 1);
	}

public:
	~ActorManager();

	void BeginPlay();
	void Update(const float _deltaTime);
	void BeginDestroy();
};