<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="15008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="rydberg_synth_vi.vi" Type="VI" URL="../rydberg_synth_vi.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
			</Item>
			<Item Name="combine1dArrays.vi" Type="VI" URL="../../../pulseblaster/RandomDelayTime/MixTauArray/combine1dArrays.vi"/>
			<Item Name="gen_freq_array.vi" Type="VI" URL="../../Table Mode/gen_freq_array.vi"/>
			<Item Name="mix_freq_array.vi" Type="VI" URL="../../Table Mode/MixFreqArray/mix_freq_array.vi"/>
			<Item Name="random_element.vi" Type="VI" URL="../../../pulseblaster/RandomDelayTime/MixTauArray/random_element.vi"/>
			<Item Name="rydberg_write_synth_channel.vi" Type="VI" URL="../rydberg_write_synth_channel.vi"/>
			<Item Name="shuffle_taus.vi" Type="VI" URL="../../../pulseblaster/RandomDelayTime/MixTauArray/shuffle_taus.vi"/>
			<Item Name="synth_channel.ctl" Type="VI" URL="../../../Controls/Synth_409b/synth_channel.ctl"/>
			<Item Name="Synth_controls.ctl" Type="VI" URL="../../../Controls/Synth_409b/Synth_controls.ctl"/>
			<Item Name="table_mode.ctl" Type="VI" URL="../../../Controls/Synth_409b/table_mode.ctl"/>
			<Item Name="write_table_mode_command.vi" Type="VI" URL="../../Table Mode/write_table_mode_command.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="rydberg_synth_vi" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{60A8B977-2F16-424A-90E0-312CE0CBEF64}</Property>
				<Property Name="App_INI_GUID" Type="Str">{CDCA91DF-E375-4BDB-9AC2-57C661E5E37D}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{1F8B5643-A321-4F88-8F20-383240AA12F5}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">rydberg_synth_vi</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/rydberg_synth_vi</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{A5583A88-5ED9-4A21-8F7E-93A3A1FE209D}</Property>
				<Property Name="Bld_version.build" Type="Int">2</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">Application.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/rydberg_synth_vi/Application.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/rydberg_synth_vi/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{2D31A545-6B24-482F-A0FA-DF48873A9D90}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/rydberg_synth_vi.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">Rice University</Property>
				<Property Name="TgtF_fileDescription" Type="Str">rydberg_synth_vi</Property>
				<Property Name="TgtF_internalName" Type="Str">rydberg_synth_vi</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2015 Rice University</Property>
				<Property Name="TgtF_productName" Type="Str">rydberg_synth_vi</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{B7323573-2D71-46C4-ACCE-50C027BF0DDF}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Application.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
