// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
static class REALISTICRENDERING_API ConsoleCommands
{
public:
	ConsoleCommands();
	~ConsoleCommands();

	UFUNCTION(exec, BlueprintImplementableEvent, meta = (FriendlyName = "MEDIA.LOAD"))
		virtual void mediaLoad();

	UFUNCTIO
};
