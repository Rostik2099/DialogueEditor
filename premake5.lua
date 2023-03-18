workspace "DialogueEditor"
	architecture "x64"
	configurations
	{
		"Debug",
		"Shipping",
		"Release",
	}
	startproject "DialogueEditor"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "DialogueEditor"