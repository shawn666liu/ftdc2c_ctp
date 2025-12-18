add_rules("mode.debug", "mode.release")

if is_os("windows") then 
    add_defines("FTDC2C_EXPORTS")    
end

if is_mode("debug") then
    add_defines("_DEBUG")
end

target("ftdc2c_ctp")
    set_kind("shared")
    add_files("*.cpp")
	if is_os("windows") then
	    add_linkdirs("api/win_x64")
        add_links("thostmduserapi_se.lib")
        add_links("thosttraderapi_se.lib")
	else
	    add_linkdirs("api/linux_x64")
        add_links("libthostmduserapi_se.so")
        add_links("libthosttraderapi_se.so")
	end