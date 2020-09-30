#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/RTSAttributeSet.h"
#include "RTSAttackAttributeSet.generated.h"

/**
 * Contains attributes about the attack of a unit or building.
 */
UCLASS(BlueprintType)
class ORDERSABILITIES_API URTSAttackAttributeSet : public URTSAttributeSet
{
    GENERATED_BODY()

    //  YOU ARE NOT ALLOWED TO CHANGE THE ATTRIBUTE VALUES!
    //
    //  This attributes are only PUBLIC because of the 'DEFINE_ATTRIBUTE_CAPTUREDEF' macro that is used when
    //  implementing a 'UGameplayEffectExecutionCalculation'.This attribute values should only be changed using
    //  GameplayEffects.
public:
    static const float MAX_DAMAGE;
    static const float MAX_COOLDOWN;
    static const float MAX_RANGE;
    static const float MAX_OUTGOING_DAMAGE_MULTIPLIER;

    /** Default attack damage. */
    UPROPERTY(Category = "Attributes|Attack", BlueprintReadOnly, ReplicatedUsing = OnRep_Damage)
    float Damage;
    UFUNCTION()
    void OnRep_Damage(const float& OldDamage);
    static const FGameplayAttribute& DamageAttribute();

    /** Time before the attack can be used again, in seconds. */
    UPROPERTY(Category = "Attributes|Attack", BlueprintReadOnly, ReplicatedUsing = OnRep_Cooldown)
    float Cooldown;
    UFUNCTION()
    void OnRep_Cooldown(const float& OldCooldown);
    static const FGameplayAttribute& CooldownAttribute();

    /** Attack range, in cm. */
    UPROPERTY(Category = "Attributes|Attack", BlueprintReadOnly, ReplicatedUsing = OnRep_Range)
    float Range;
    UFUNCTION()
    void OnRep_Range(const float& OldRange);
    static const FGameplayAttribute& RangeAttribute();

    /**
     * The OutgoingDamageMultiplier of a target is multiplied with incoming damage to modify the loss of hit points of
     * the attacked unit.
     */
    UPROPERTY(Category = "Attributes|Attack", BlueprintReadOnly, ReplicatedUsing = OnRep_OutgoingDamageMultiplier)
    float OutgoingDamageMultiplier;
    UFUNCTION()
    void OnRep_OutgoingDamageMultiplier(const float& OldOutgoingDamageMultiplier);
    static const FGameplayAttribute& OutgoingDamageMultiplierAttribute();

    //~ Begin UAttributeSet Interface
    virtual bool ShouldInitProperty(bool FirstInit, FProperty* PropertyToInit) const override;
    virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
    //~ End UAttributeSet Interface

    //~ Begin URTSAttributeSet Interface
    virtual void PostInitializeProperties(bool bInitialInit) override;
    virtual void GetDefaultStatusTags(FGameplayTagContainer& OutStatusTags) const override;
    //~ End URTSAttributeSet Interface
};
