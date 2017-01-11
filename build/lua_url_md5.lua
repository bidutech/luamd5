function sumhexa (k)
  k = LOCMD5(k)
  return (string.gsub(k, ".", function (c)
           return string.format("%02x", string.byte(c))
         end))
end

function getKey(url)
    print("run...lua...")
    print(url)
    return sumhexa(url)
end


function getKey2(url)
    print("run...lua...")
    print(url)
    return sumhexa(url),"1.0.0.1"
end
