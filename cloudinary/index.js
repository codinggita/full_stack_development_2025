// Connecting with Cloudinary
const cloudinary = require("cloudinary").v2;

cloudinary.config({
    cloud_name: "name",
    api_key: "key",
    api_secret: "secret",
});

const react = "./images/react.png";
const video = "./videos/video.mp4";
// function to upload image , and return image url

const uploadImage = async (react) => {
  try {
    const results = await cloudinary.uploader.upload(react);
    console.log("Image Obj: ", results);
    console.log("Image URL: ", results.secure_url);
    return results.secure_url;
  } catch (error) {
    console.error(error);
    return null;
  }
};

const uploadVideo = async (video) => {
  try {
    const results = await cloudinary.uploader.upload(video, {
      resource_type: "video",
    });
    // console.log("Video: ", results.secure_url);
    return results.secure_url;
  } catch (error) {
    console.error(error);
    return null;
  }
};
uploadImage(react);
// uploadVideo(video);
