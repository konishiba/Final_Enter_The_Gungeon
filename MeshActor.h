#pragma once
#include "Actor.h"
#include "StaticMeshComponent.h"
#include "TextureManager.h"

class AMeshActor : public AActor
{
protected:
	UStaticMeshComponent* mesh;

public:
	FORCEINLINE UStaticMeshComponent* GetMesh() const
	{
		return mesh;
	}
	FORCEINLINE FloatRect GetHitbox() const
	{
		return mesh->GetShape()->GetDrawable()->getGlobalBounds();
	}  
	FORCEINLINE void SetTextureRect(const Vector2i& _start, const Vector2i& _size)
	{
		SetTextureRect(IntRect(_start, _size));
	}
	FORCEINLINE void SetTextureRect(const IntRect& _rect)
	{
		M_TEXTURE.SetTextureRect(mesh->GetShape()->GetDrawable(), _rect);
	}

	#pragma region Modifier
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		Super::SetPosition(_position);
		mesh->GetShape()->SetPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		Super::SetRotation(_rotation);
		mesh->GetShape()->SetRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		Super::SetScale(_scale);
		mesh->GetShape()->SetScale(_scale);
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		Super::SetOrigin(_origin);
		mesh->GetShape()->SetOrigin(_origin);
	}

	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
		mesh->GetShape()->Move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		Super::Rotate(_angle);
		mesh->GetShape()->Rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		Super::Scale(_factor);
		mesh->GetShape()->Scale(_factor);
	}
	#pragma endregion

public:
	AMeshActor() = default;
	AMeshActor(Level* _level, const CircleShapeData& _data, const string& _name = "MeshActor");
	AMeshActor(Level* _level, const RectangleShapeData& _data, const string& _name = "MeshActor");
	AMeshActor(const AMeshActor& _other);

public:
	virtual void SetZOrder(const int _zOrder) override;
};