#include "Animation.h"
#include "TextureManager.h"

Animation::Animation(const string& _name, ShapeObject* _shape, const AnimationData& _data)
{
	currentIndex = 0;
	name = _name;
	data = _data;
	shape = _shape;
	timer = new Timer(
		[&]() { Update(); },
		seconds(ComputeDuration()),
		false,
		true
	);
}

Animation::Animation(const Animation& _other)
{
	currentIndex = _other.currentIndex;
	name = _other.name;
	data = _other.data;
	shape = _other.shape;
	timer = _other.timer;
}

Animation::~Animation()
{
	timer->Stop();
}


void Animation::Update()
{
	if (!IsValidIndex())
	{
		if (!data.canLoop)
		{
			onAnimationEnded();
			Stop();
			return;
		}

		//TODO remove
		onAnimationEnded();
		Reset();
	}

	if (data.isReversed)
	{
		shape->SetScale(Vector2f(-1.0f, 1.0f));
	}

	++currentIndex;

	map<u_int, function<void()>> _notifies = data.notifies;
	if (_notifies.contains(currentIndex))
	{
		_notifies[currentIndex]();
	}

	const SpriteData& _spriteData = *GetSpriteData();
	UpdateTimer(_spriteData);
	M_TEXTURE.SetTextureRect(shape->GetDrawable(), _spriteData.start, _spriteData.size);
}

void Animation::UpdateTimer(const SpriteData& _spriteData)
{
	const float _duration = ComputeDuration(_spriteData);
	timer->SetDuration(_duration);
	timer->Reset();
}

void Animation::Reset()
{
	currentIndex = 0;
	timer->Reset();
}


void Animation::Start()
{
	Update();
	timer->Start();
}

void Animation::Resume()
{
	timer->Resume();
}

void Animation::Pause()
{
	timer->Pause();
}

void Animation::Stop()
{
	Pause();
	Reset();
}