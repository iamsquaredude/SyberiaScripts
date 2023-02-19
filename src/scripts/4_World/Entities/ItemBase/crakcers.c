

modded class Zagorky_ColorBase: Edible_Base
{
	
	bool IsTemperatureVisible()
	{
		return !CanHaveTemperature();
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeedSmall);
		AddAction(ActionEatSmall);
	}
};

modded class Snack_ColorBase: Edible_Base
{
	bool IsTemperatureVisible()
	{
		return !CanHaveTemperature();
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeedSmall);
		AddAction(ActionEatSmall);
	}
};

modded class PowderedMilk: Edible_Base
{
	bool IsTemperatureVisible()
	{
		return !CanHaveTemperature();
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatBig);
	}
};

modded class Rice: Edible_Base
{
	bool IsTemperatureVisible()
	{
		return !CanHaveTemperature();
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatBig);
	}
};

modded class VitaminBottle : Edible_Base
{
	bool IsTemperatureVisible()
	{
		return !CanHaveTemperature();
	}
	
	//Specify this item can only be combined but not split
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}
	
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if( consumer.GetModifiersManager().IsModifierActive(eModifiers.MDF_IMMUNITYBOOST ) )//effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier( eModifiers.MDF_IMMUNITYBOOST );
		}
		consumer.GetModifiersManager().ActivateModifier( eModifiers.MDF_IMMUNITYBOOST );
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
		//AddAction(ActionForceFeed);
		//AddAction(ActionEatBig);
	}
}

modded class BoxCerealCrunchin extends Edible_Base
{
	void BoxCerealCrunchin()
	{
	}
	
	bool IsTemperatureVisible()
	{
		return !CanHaveTemperature();
	}
	
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEat);
	}
}
